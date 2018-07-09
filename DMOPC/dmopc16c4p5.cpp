#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m, a, b, c;
    scanf("%i%i", &n, &m);
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> dist (n+1, 0);
    vector<bool> vis(n+1, false);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    queue<int> buf;
    buf.push(1);
    dist[1] = INT_MAX;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        vis[u] = false;
        for (auto &x : adj[u])
        {
            if (min(dist[u], x.second) > dist[x.first])
            {
                dist[x.first] = min(dist[u], x.second);
                if (!vis[x.first])
                {
                    vis[x.first] = true;
                    buf.push(x.first);
                }
            }
        }
    }
    dist[1] = 0;
    for (int x = 1; x <= n; x++)
        printf("%i\n", dist[x]);
}
