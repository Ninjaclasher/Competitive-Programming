#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<vector<int>> adj(MAXN);
vector<int> sz(MAXN);
vector<int> pari(MAXN);
vector<bool> vis(MAXN);

int dfs(int u, int p)
{
    sz[u] = 1;
    for (auto &x : adj[u])
        if (x != p && !vis[x])
            sz[u] += dfs(x, u);
    return sz[u];
}

int centroid(int u, int p, int nn)
{
    for (auto &x : adj[u])
        if (x != p && !vis[x] && sz[x]*2 > nn)
            return centroid(x, u, nn);
    return u;
}

int act = 0;

int dfs2(int u, int p, int pp)
{
    if (pari[u] != pp)
        return 0;
    if (pp == 1)
        act++;
    int cnt = 1;
    for (auto &x : adj[u])
        if (x != p && !vis[x])
            cnt += dfs2(x, u, pp^1);
    return cnt;
}

long long ans = 0;

void solve(int c)
{
    dfs(c, c);
    c = centroid(c, c, sz[c]);
    vis[c] = true;
    long long cur = pari[c];
    long long cur2 = 1;
    ans += pari[c];
    for (auto &x : adj[c])
    {
        if (!vis[x])
        {
            act = 0;
            int c1 = dfs2(x, c, pari[c] ^ 1);
            ans += cur * c1 + act * cur2;
            cur2 += c1;
            cur += act;
        }
    }
    for (auto &x : adj[c])
        if (!vis[x])
            solve(x);
}

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &pari[x]);
        pari[x] &= 1;
    }
    int a, b;
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(1);
    printf("%lli\n", ans);
}
