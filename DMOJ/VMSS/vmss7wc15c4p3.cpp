#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(100001);
vector<bool> vis (100001);

void BFS(int src, vector<int> &dist)
{
    fill(vis.begin(), vis.end(), false);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[src] = 0;
    queue<int> buf;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        vis[u] = false;
        for (auto &x : adj[u])
        {
            if (dist[u]+x.second < dist[x.first])
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
    int n, m, a, b, c, ma = 0;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    vector<int> dis1 (n+1), dis2(n+1);
    BFS(0, dis1);
    BFS(n-1, dis2);
    for (int x = 0; x < n; x++)
        ma = max(ma, dis1[x]+dis2[x]);
    printf("%i", ma);
    return 0;
}
