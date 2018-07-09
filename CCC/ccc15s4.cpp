#include <bits/stdc++.h>

using namespace std;

struct ed
{
    int b, t, h;  
};

vector<vector<ed>> adj(5005);
vector<bool> vis(2005);
vector<vector<int>> dist(2005, vector<int>(205, INT_MAX));

int main() 
{
    int k, n, m, a, b, c, d;
    scanf("%i%i%i", &k, &n, &m);
    while (m--)
    {
        scanf("%i%i%i%i", &a, &b, &c, &d);
        adj[a].push_back({b, c, d});
        adj[b].push_back({a, c, d});
    }
    scanf("%i%i", &a, &b);
    dist[a][k] = 0;
    queue<int> buf;
    buf.push(a);
    while (!buf.empty())
    {
        int u = buf.front(); buf.pop();
        vis[u] = false;
        for (int t = 1; t <= k; t++)
        {
            if (dist[u][t] != INT_MAX)
            {
                for (auto &x : adj[u])
                {
                    if (t-x.h > 0 && dist[u][t] + x.t < dist[x.b][t-x.h])
                    {
                        dist[x.b][t-x.h] = dist[u][t] + x.t;
                        if (!vis[x.b])
                            vis[x.b] = true, buf.push(x.b);
                    }
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int x = 1; x <= k; x++)
        ans = min(ans, dist[b][x]);
    printf("%i", ans == INT_MAX ? -1 : ans);
    return 0;
}
