#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1000005;

int n, m;

vector<vector<int>> arr;
vector<vector<int>> mp;
vector<vector<bool>> vis;

int cc = 0;

vector<vector<pair<int,int>>> adj(MAXV);
vector<int> dist(MAXV, INT_MAX);


int main()
{
    scanf("%i%i", &n, &m);
    arr = vector<vector<int>>(n, vector<int>(m));
    mp = vector<vector<int>>(n, vector<int>(m));
    vis = vector<vector<bool>>(n, vector<bool>(m));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            char c;
            scanf(" %c", &c);
            arr[x][y] = (c == '#');
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (vis[x][y] || !arr[x][y])
                continue;
            ++cc;
            vis[x][y] = 1;
            mp[x][y] = cc;
            queue<pair<int,int>> buf;
            buf.push({x, y});
            while (!buf.empty())
            {
                int xx = buf.front().first, yy = buf.front().second;
                buf.pop();
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if ((dx == 0 && dy == 0) || (dx != 0 && dy != 0))
                            continue;
                        int nx = xx + dx;
                        int ny = yy + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] && !vis[nx][ny])
                        {
                            vis[nx][ny] = 1;
                            mp[nx][ny] = cc;
                            buf.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    ++cc;
    for (int y = 0; y < m; y++)
    {
        int prevMp = -1, prev = -1;
        for (int x = 0; x < n; x++)
        {
            if (arr[x][y])
            {
                if (~prev)
                    adj[mp[x][y]].push_back({prevMp, x - prev - 1});
                prev = x, prevMp = mp[x][y];
            }
        }
        if (~prev)
            adj[cc].push_back({prevMp, n - prev - 1});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> buf;
    buf.push({0, cc});
    dist[cc] = 0;
    while(!buf.empty())
    {
        int u = buf.top().second, w = buf.top().first;
        buf.pop();
        if (w > dist[u])
            continue;
        for (auto &x : adj[u])
        {
            if (dist[x.first] > dist[u] + x.second)
            {
                dist[x.first] = dist[u] + x.second;
                buf.push({dist[x.first], x.first});
            }
        }
    }
    vector<vector<int>> ne = vector<vector<int>>(n, vector<int>(m));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (arr[x][y])
                ne[x + dist[mp[x][y]]][y] = 1;
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
            printf("%c", ne[x][y] ? '#' : '.');
        printf("\n");
    }
}
