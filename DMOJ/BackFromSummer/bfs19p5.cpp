#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int LOGN = 18;

vector<int> h(MAXN);
vector<long long> down(MAXN), up(MAXN), sz(MAXN);
vector<vector<int>> adj(MAXN), spt(LOGN, vector<int>(MAXN));
int n;

long long dfs1(int u, int p)
{
    h[u] = h[p] + 1;
    spt[0][u] = p;
    sz[u] = 1;
    for (auto &x : adj[u])
        if (x != p)
            sz[u] += dfs1(x, u);
    return sz[u];
}

void build()
{
    for (int x = 1; x < LOGN; x++)
        for (int y = 1; y <= n; y++)
            spt[x][y] = spt[x-1][spt[x-1][y]];
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    int d = h[b]-h[a];
    for (int x = 0; x < LOGN; x++)
        if (d>>x&1)
            b = spt[x][b];
    if (a == b)
        return a;
    for (int x = LOGN-1; x >= 0; x--)
        if (spt[x][a] != spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

int dist(int a, int b)
{
    return h[a] + h[b] - 2 * h[lca(a, b)];
}

long long dfs2(int u, int p)
{
    for (auto &x : adj[u])
        if (x != p)
            down[u] += dfs2(x, u) + sz[x];
    return down[u];
}

void dfs3(int u, int p, long long curdown=0)
{
    up[u] = curdown;
    for (auto &x : adj[u])
        if (x != p)
            curdown += down[x] + sz[x];
    for (auto &x : adj[u])
    {
        if (x != p)
        {
            curdown -= down[x] + sz[x];
            dfs3(x, u, curdown + (n - sz[x]));
            curdown += down[x] + sz[x];
        }
    }
}

int main()
{
    int q, a, b;
    scanf("%i%i", &n, &q);
    assert(1 <= n && n <= 100000);
    assert(1 <= q && q <= 100000);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 1);
    build();
    dfs2(1, 1);
    dfs3(1, 1);
    while (q--)
    {
        scanf("%i%i", &a, &b);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        int c = lca(a, b);
        assert(c != a && c != b);
        // the cancer line
        long long v = (-up[a] + dist(a, b) * sz[b] + down[b]) * (sz[a] - sz[b]) + (-up[b] + dist(a, b) * sz[a] + down[a]) * (sz[b] - sz[a]);
        printf("%lli\n", !v ? 0 : v / abs(v));
    }
}
