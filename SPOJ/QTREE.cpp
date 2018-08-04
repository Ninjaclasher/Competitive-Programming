#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

vector<vector<pair<int,int>>> adj(10005);
int sz[10005], hev[10005], hevw[10005], top[10005], par[10005], mp[10005], h[10005], arr[10005], st[20005], cc = 1;

static inline __attribute__((always_inline)) int maxx(int a, int b)
{
    return a < b ? b : a;
}

static inline __attribute__((always_inline)) void sswap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

static void dfs(int u, int p)
{
    sz[u] = 1;
    h[u] = h[p]+1;
    par[u] = p;
    int ma = 0;
    for (auto &x : adj[u])
    {
        if (x.first ^ p)
        {
            dfs(x.first, u);
            if (sz[x.first] > ma)
                ma = sz[x.first], hev[u] = x.first, hevw[u] = x.second;
            sz[u] += sz[x.first];
        }
    }
}

static void dfs2(int u, int p, int w)
{
    top[u] = (hev[p] ^ u) ? u : top[p];
    mp[u] = cc;
    arr[cc] = w;
    cc++;
    if (hev[u])
        dfs2(hev[u], u, hevw[u]);
    for (auto &x : adj[u])
        if (x.first != p && x.first != hev[u])
            dfs2(x.first, u, x.second);
}

static inline __attribute__((always_inline)) void build()
{
    for (int x = cc; x < (cc<<1); x++)
        st[x] = arr[x-cc+1];
    for (int x = cc-1; x > 0; x--)
        st[x] = maxx(st[x<<1], st[x<<1|1]);
}

static inline __attribute__((always_inline)) void update(int i, int v)
{
    st[i += cc-1] = v;
    for (i>>=1; i; i>>=1)
        st[i] = maxx(st[i<<1], st[i<<1|1]);
}

static inline __attribute__((always_inline)) int query(int l, int r)
{
    int ma = 0;
    for (l += cc-1, r += cc; l < r; l>>=1, r>>=1)
    {
        if (l&1)
            ma = maxx(ma, st[l++]);
        if (r&1)
            ma = maxx(ma, st[--r]);
    }
    return ma;
}

static inline __attribute__((always_inline)) int qMax(int a, int b)
{
    int ma = 0;
    while (top[a] ^ top[b])
    {
        if (h[top[a]] > h[top[b]])
            sswap(a, b);
        ma = maxx(ma, query(mp[top[b]], mp[b]));
        b = par[top[b]];
    }
    if (h[a] > h[b])
        sswap(a, b);
    if (a ^ b)
        return maxx(ma, query(mp[hev[a]], mp[b]));
    return ma;
}

int main()
{
    int t;
    char* buf = new char[10];
    scanf("%i", &t);
    while (t--)
    {
        int n, a, b, c;
        vector<pair<int,int>> edd;
        h[1] = 0;
        cc = 1;
        fill(adj.begin(), adj.end(), vector<pair<int,int>>());
        memset(hev, 0, 40020);
        scanf("%i", &n);
        for (int x = 1; x < n; x++)
        {
            scanf("%i%i%i", &a, &b, &c);
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
            edd.push_back({a, b});
        }
        dfs(1, 1);
        dfs2(1, 1, 0);
        build();
        scanf(" %s", buf);
        while (buf[0] != 'D')
        {
            scanf("%i%i", &a, &b);
            if (buf[0] == 'C')
            {
                --a;
                int i = h[edd[a].first] > h[edd[a].second] ? edd[a].first : edd[a].second;
                update(mp[i], b);
            }
            else if (buf[0] == 'Q')
                printf("%i\n", qMax(a, b));
            else
                abort();
            scanf(" %s", buf);
        }
    }
}

