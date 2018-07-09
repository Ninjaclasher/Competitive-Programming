#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(35000);
vector<int> dist(35000, INT_MAX);
vector<bool> vis(35000);

int main()
{
    int n, m, b, p, d, dd;
    scanf("%i%i", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i", &b, &p);
        if (!x) d = b;
        else if (x == 1) dd = b;
        adj[b].push_back(p);
    }
    queue<int> buf;
    dist[d] = 0;
    buf.push(d);
    while (!buf.empty())
    {
        int u = buf.front();
        vis[u] = false;
        buf.pop();
        for (auto &x : adj[u])
        {
            int t = u, j = 0;
            while ((t-=x) >= 0)
            {
                if (dist[u]+(++j) < dist[t])
                {
                    dist[t] = dist[u]+j;
                    if (!vis[t])
                        vis[t] = true, buf.push(t);
                }
            }
            t = u, j = 0;
            while ((t+=x) < n)
            {
                if (dist[u]+(++j) < dist[t])
                {
                    dist[t] = dist[u]+j;
                    if (!vis[t])
                        vis[t] = true, buf.push(t);
                }                
            }
        }
    }
    printf("%i", dist[dd] == INT_MAX ? -1 : dist[dd]);
}
