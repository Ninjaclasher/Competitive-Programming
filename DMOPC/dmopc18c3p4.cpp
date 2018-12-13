#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<vector<pair<int,int>>> adj(MAXN);
vector<int> student(MAXN);
vector<int> sz(MAXN);
vector<long long> dist(MAXN);

int dfs(int u, int p)
{
    sz[u] = student[u];
    for (auto &x : adj[u])
        if (x.first ^ p)
            sz[u] += dfs(x.first, u);
    return sz[u];
}

int n, k;

int centroid(int u, int p)
{
    for (auto &x : adj[u])
        if ((x.first ^ p) && sz[x.first]*2 > k)
            return centroid(x.first, u);
    return u;
}

void dfs2(int u, int p, int w)
{
    dist[u] = dist[p] + w;
    for (auto &x : adj[u])
        if (x.first ^ p)
            dfs2(x.first, u, x.second);
}

int main()
{
    scanf("%i%i", &k, &n);
    int a, b, c, d;
    for (int x = 0; x < k; x++)
    {
        scanf("%i", &d);
        student[d]++;
    }
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(d, d);
    c = centroid(d, d);
    dfs2(c, c, 0);
    long long ans = 0;
    for (int x = 1; x <= n; x++)
        ans += dist[x] * student[x];
    printf("%lli\n", ans);
}

