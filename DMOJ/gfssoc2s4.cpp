#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<pair<int,int>>>> adj(2, vector<vector<pair<int,int>>>(500001));nv
vector<vector<long long>> dist(2, vector<long long> (500001, INT_MAX));
vector<bool> vis(500001);

void BFS(int src)
{
    int n = (src == 1 ? 0 : 1);
    dist[n][src] = 0;
    queue<int> buf;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        vis[u] = false;
        for (auto &x : adj[n][u])
        {
            if (dist[n][u]+x.second < dist[n][x.first])
            {
                dist[n][x.first] = dist[n][u]+x.second;
                if (!vis[x.first])
                    vis[x.first] = true, buf.push(x.first);
            }
        }
    }
}

int main()
{
    int n, m, a, b, c, d;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[0][a].push_back(make_pair(b, c));
        adj[1][b].push_back(make_pair(a, c));
    }
    BFS(1);
    BFS(n);
    long long ma = dist[0][n];
    scanf("%i", &d);
    while (d--)
    {
        scanf("%i%i%i", &a, &b, &c);
        ma = min(ma, dist[0][a] + c + dist[1][b]);
    }
    printf("%lli", ma == INT_MAX ? -1 : ma);
}
