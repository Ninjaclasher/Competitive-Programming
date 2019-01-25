#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<int>> gr(31, vector<int>(31, 2));
vector<vector<int>> w(31, vector<int>(31));
vector<vector<vector<pair<int,int>>>> adj(31, vector<vector<pair<int,int>>>(31));
vector<vector<vector<pair<int,int>>>> adj2(31, vector<vector<pair<int,int>>>(31));

static inline __attribute__((always_inline)) bool bound(int a, int b)
{
    return a >= 0 && a < r && b >= 0 && b < c;
}

template <typename T>
static inline __attribute__((always_inline)) T get(pair<int,int> p, vector<vector<T>> &arr)
{
    return arr[p.first][p.second];
}

int main()
{
    pair<int,int> s, e;
    vector<pair<int,int>> pos ({
        { 1, 2},
        {-1, 2},
        { 1,-2},
        {-1,-2},
        { 2, 1},
        { 2,-1},
        {-2, 1},
        {-2,-1}
    });
    scanf("%i%i", &r, &c);
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            scanf("%i", &gr[x][y]);
            if (gr[x][y] == 3)
                s = make_pair(x, y);
            else if (gr[x][y] == 4)
                e = make_pair(x, y);    
        }
    }
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            if (gr[x][y] == 2)
                continue;
            w[x][y] = !gr[x][y];
            for (auto &z : pos)
            {
                int nx = x+z.first, ny = y+z.second;
                if (bound(nx, ny) && gr[nx][ny] != 2)
                    adj[x][y].push_back({nx, ny});
            }
        }
    }
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            if (gr[x][y] == 1 || gr[x][y] == 2)
                continue;
            vector<vector<int>> dist(31, vector<int> (31, INT_MAX));
            queue<pair<int,int>> buf;
            buf.push({x, y});
            dist[x][y] = w[x][y];
            while (!buf.empty())
            {
                auto u = buf.front();
                buf.pop();
                for (auto &x : adj[u.first][u.second])
                {
                    if (get(u, dist)+get(x, w) < get(x, dist))
                    {
                        dist[x.first][x.second] = get(u, dist)+get(x, w);
                        buf.push(x);
                    }
                }
            }
            for (int xx = 0; xx < r; xx++)
            {
                for (int yy = 0; yy < c; yy++)
                {
                    if (x == xx && y == yy)
                        continue;
                    if (dist[xx][yy] == (!gr[x][y] + !gr[xx][yy]))
                        adj2[x][y].push_back({xx, yy});
                }
            }
        }
    }
    vector<vector<int>> dist(31, vector<int>(31, INT_MAX));
    vector<vector<long long>> dp(31, vector<long long>(31));
    queue<pair<int,int>> buf;
    buf.push(s);
    dist[s.first][s.second] = 0;
    dp[s.first][s.second] = 1;
    while (!buf.empty())
    {
        auto u = buf.front();
        buf.pop();
        for (auto &x : adj2[u.first][u.second])
        {
            int v = get(u, dist)+1;  
            if (v < get(x, dist))
            {
                dp[x.first][x.second] = get(u, dp);
                dist[x.first][x.second] = v;
                buf.push(x);
            }
            else if (v == get(x, dist))
                dp[x.first][x.second] += get(u, dp);
        }
    }
    if (get(e, dist) == INT_MAX)
        return 0 * printf("-1\n");
    printf("%i\n%lli\n", get(e, dist)-1, get(e, dp));
}
