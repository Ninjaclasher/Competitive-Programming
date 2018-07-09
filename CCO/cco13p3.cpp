#include <bits/stdc++.h>

using namespace std;

vector<long long> dist, cc;
vector<vector<int>> adj;

long long dfs(int u, int p, long long &maxV, long long &maxDiam)
{
    if (adj[u].size() == 1 && u != p)
        return 0;
    for (auto &x : adj[u])
    {
        if (x != p)
        {
            long long thisDiam = dfs (x, u, maxV, maxDiam) + 1;
            if (thisDiam + dist[u] > maxDiam)
                maxDiam = thisDiam + dist[u], maxV = cc[x] * cc[u];
            else if (thisDiam + dist[u] == maxDiam)
                maxV += cc[x] * cc[u];
            if (thisDiam > dist[u]) 
                dist[u] = thisDiam, cc[u] = cc[x];
            else if (thisDiam == dist[u]) 
                cc[u] += cc[x];
        }
    }
    return dist[u];
}

int main()
{
    int n, a, b;
    long long vv = 0, diam = 0;
    scanf("%i", &n);
    adj.resize(n+1), dist.resize(n+1), cc.resize(n+1, 1);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs (1, 1, vv, diam);
    printf("%lli %lli\n", diam+1, vv);
    return 0;
}
