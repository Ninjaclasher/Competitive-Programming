#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

vector<vector<int>> adj;
vector<long long> dist (10001, -1);
vector<int> vis(10001), keep(10001);

int prune(int u)
{
    if (vis[u])
        return keep[u];
    vis[u] = 1;
    if (u == 1)
        keep[u] = 1;
    for (auto &x : adj[u])
        keep[u] |= prune(x);
    return keep[u];
}

long long DFS(int v)
{
    if (dist[v] != -1) return dist[v];
    dist[v] = 0;
    vis[v] = 1;
    for (auto &x : adj[v])
    {
        if (!keep[x])
            continue;
        if (vis[x] == 1)
        {
            printf("inf\n");
            exit(0);
        }
        dist[v] += DFS(x);
        if (dist[v] >= MOD)
        {
            dist[v] %= MOD;
            dist[v] += MOD;
        }
    }
    vis[v] = 2;
    return dist[v];
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    adj.resize(n);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        a--, b--;
        adj[a].push_back(b);
    }
    prune(0);
    fill(vis.begin(), vis.end(), 0);
    dist[1] = 1;
    long long ans = DFS(0);
    if (ans >= MOD)
        printf("%09lli\n", ans % MOD);
    else
        printf("%lli\n", ans % MOD);
    return 0;
}
