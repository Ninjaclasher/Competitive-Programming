#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1<<20);
vector<bool> vis(1<<20);

int n, m, a, b, c;

int g(int x, int y)
{
    return x*m + y;
}

int nextState(int cur)
{
    int nxt = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            int cc = g(x, y);
            int cnt = 0;
            for (int xx = -1; xx <= 1; xx++)
                for (int yy = -1; yy <= 1; yy++)
                    if ((xx || yy) && x+xx >= 0 && x+xx < n && y+yy >= 0 && y+yy < m)
                        cnt += (cur>>g(x+xx, y+yy))&1;
            if (cur>>cc&1)
            {
                if (a <= cnt && cnt <= b)
                    nxt |= (1<<cc);
            }
            else
            {
                if (cnt > c)
                    nxt |= (1<<cc);
            }
        }
    }
    return nxt;
}

int main()
{
    //NOTE: n and m are switched;
    scanf("%i%i%i%i%i", &n, &m, &a, &b, &c);
    for (int x = 0; x < (1<<(n*m)); x++)
        adj[nextState(x)].push_back(x);
    int cur = 0;
    char t;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            scanf(" %c", &t);
            if (t == '*')
                cur |= 1<<g(x, y);
        }
    }
    queue<pair<int,int>> buf;
    buf.push({cur, 0});
    while (!buf.empty())
    {
        pair<int,int> u = buf.front();
        buf.pop();
        if (adj[u.first].empty())
            return 0 * printf("%i\n", u.second);
        for (auto &x : adj[u.first])
            if (!vis[x])
                buf.push({x, u.second+1}), vis[x] = true;
    }
    printf("-1\n");
}
