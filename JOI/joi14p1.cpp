#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(500002);
vector<bool> vis(500002);
vector<int> sz(500002), used(500002);
vector<long long> m(500002);
vector<vector<pair<int, long long>>> par(500002);
vector<vector<long long>> dist(20, vector<long long>(500002));
int cc = 0, nn, c;

int dfs(int u, int p)
{
    sz[u] = 1;
    for (auto &x : adj[u])
        if (x.first ^ p && !vis[x.first])
            sz[u] += dfs(x.first, u);
    return sz[u];
}

int centroid(int u, int p, int n)
{
    for (auto &x : adj[u])
        if (x.first ^ p && !vis[x.first] && sz[x.first]*2 > n)
            return centroid(x.first, u, n);
    return u;
}

int dfs2(int s, int lvl, int u, int p, long long d)
{
    sz[u] = 1;
    par[u].push_back({c, d});
    for (auto &x : adj[u])
        if (x.first ^ p && !vis[x.first])
            sz[u] += dfs2(s, lvl, x.first, u, d+x.second);
    return sz[u];
}

void solve(int u, int l)
{
    c = centroid(u, u, sz[u]);
    dfs2(c, l, c, c, 0);
    vis[c] = true;
    for (auto &x : adj[c])
        if (!vis[x.first])
            solve(x.first, l+1);
}

void Init(int n, int a[], int b[], int c[])
{
    nn = ceil(log2(n)) - 1;
    for (int x = 0; x < n-1; x++)
        adj[a[x]].push_back({b[x], c[x]}), adj[b[x]].push_back({a[x], c[x]});
    dfs(1, 1);
    solve(1, 0);
}

long long Query(int s, int a[], int t, int b[])
{
    cc++;
    long long mi = LONG_MAX;
    for (int i = 0; i < s; i++)
        for (auto &x : par[a[i]])
            m[x.first] = min((used[x.first] == cc ? m[x.first] : LONG_MAX), x.second), used[x.first] = cc;
    for (int i = 0; i < t; i++)
        for (auto &x : par[b[i]])
            mi = min(mi, (used[x.first] == cc ? m[x.first] + x.second : LONG_MAX));
    return mi;
}
