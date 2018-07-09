#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(1005);
vector<int> dist(1005, INT_MAX);
vector<bool> vis(1005);

void BFS()
{
    queue<int> buf;
    buf.push(1);
    dist[1] = 0;
    while (!buf.empty())
    {
        int u = buf.front(); buf.pop();
        vis[u] = false;
        for (auto &x : adj[u])
        {
            if (dist[u] + x.second < dist[x.first])
            {
                dist[x.first] = dist[u]+x.second;
                if (!vis[x.first])
                    vis[x.first] = true, buf.push(x.first);
            }
        }
    }
}

int main()
{
    int n, m, a, b, c;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    BFS();
    for (int x = 1; x <= n; x++)
        printf("%i\n", dist[x] == INT_MAX ? -1 : dist[x]);
}
