#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(100005);
unordered_map<int,int> freq;
vector<int> sz(100005), ch;
vector<bool> vis(100005);
long long ans = 0;

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

void path(int u, int p, int s)
{
    ch.push_back(s);
    ans += freq[1-s] + freq[-1-s];
    for (auto &x : adj[u])
        if (x.first ^ p && !vis[x.first])
            path(x.first, u, s + x.second);
}

void solve(int u, int p)
{
    dfs(u, u);
    u = centroid(u, u, sz[u]);
    freq.clear();
    freq[0] = vis[u] = 1;
    for (auto &x : adj[u])
    {
        if (!vis[x.first])
        {
            ch.clear();
            path(x.first, u, x.second);
            for (auto &y : ch)
                freq[y]++;
        }
    }
    for (auto &x : adj[u])
        if (!vis[x.first])
            solve(x.first, u);
}

int main()
{
    int n, a, b;
    char c;
    scanf("%i", &n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i %c", &a, &b, &c);
        adj[a].push_back({b, c == 'r' ? 1 : -1});
        adj[b].push_back({a, c == 'r' ? 1 : -1});
    }
    solve(1, 1);
    printf("%lli", ans - n + 1);
}
