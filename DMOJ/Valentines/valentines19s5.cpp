#include <bits/stdc++.h>

using namespace std;

const int MAXH = 18;
const int MAXN = 100005;

struct node
{
    bool lazymod;
    int lazy;
    int ma;
    int id;
};

vector<vector<int>> adj(MAXN);
int spt[MAXH][MAXN];
vector<int> h(MAXN), top(MAXN), hev(MAXN), sz(MAXN), mp(MAXN), revmp(MAXN);
int cc = 0;

int n;

node st[MAXN<<2];

void build(int l, int r, int v)
{
    st[v].id = l;
    if (l == r)
        return;
    int m = l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
}

void pushdown(int l, int r, int v)
{
    if (st[v].lazymod)
    {
        if (l ^ r)
            st[v<<1].lazy = st[v<<1|1].lazy = 0, st[v<<1].lazymod = st[v<<1|1].lazymod = 1;
        st[v].ma = 0;
        st[v].id = l;
        st[v].lazymod = 0;
    }
    if (st[v].lazy)
    {
        if (l ^ r)
        {
            st[v<<1].lazy += st[v].lazy;
            st[v<<1|1].lazy += st[v].lazy;
        }
        st[v].ma += st[v].lazy;
        st[v].lazy = 0;
    }
}

void update(int l, int r, int v, int li, int ri, int val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return;
    if (l >= li && r <= ri)
    {
        st[v].lazy = val;
        pushdown(l, r, v);
        return;
    }
    int m = l+r>>1;
    update(l, m, v<<1, li, ri, val);
    update(m+1, r, v<<1|1, li, ri, val);
    if (st[v<<1].ma >= st[v<<1|1].ma)
    {
        st[v].ma = st[v<<1].ma;
        st[v].id = st[v<<1].id;
    }
    else
    {
        st[v].ma = st[v<<1|1].ma;
        st[v].id = st[v<<1|1].id;
    }
}

void dfs(int u, int p)
{
    sz[u] = 1;
    h[u] = h[p] + 1;
    spt[0][u] = p;
    for (auto &x : adj[u])
    {
        if (x ^ p)
        {
            dfs(x, u);
            sz[u] += sz[x];
            if (sz[x] > sz[hev[u]])
                hev[u] = x;
        }
    }
}

void dfs2(int u, int p)
{
    top[u] = (hev[p] == u ? top[p] : u);
    ++cc;
    mp[u] = cc;
    revmp[cc] = u;
    if (hev[u])
        dfs2(hev[u], u);
    for (auto &x : adj[u])
        if (x != hev[u] && x != p)
            dfs2(x, u);
}

void build()
{
    for (int x = 1; x < MAXH; x++)
        for (int y = 1; y <= n; y++)
            spt[x][y] = spt[x-1][spt[x-1][y]];
}

static inline int jump(int a, int d)
{
    for (int x = 0; x < MAXH; x++)
        if (d>>x&1)
            a = spt[x][a];
    return a;
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    b = jump(b, h[b] - h[a]);
    if (a == b)
        return a;
    for (int x = MAXH-1; x >= 0; x--)
        if (spt[x][a] != spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

void pathUpdate(int a, int b, int v)
{
    while (top[a] != top[b])
    {
        if (h[top[a]] > h[top[b]])
            swap(a, b);
        update(1, cc, 1, mp[top[b]], mp[b], v);
        b = spt[0][top[b]];
    }
    if (h[a] > h[b])
        swap(a, b);
    update(1, cc, 1, mp[a], mp[b], v);
    pushdown(1, cc, 1);
}

bool onPath(int a, int b, int r)
{
    int c = lca(a, b);
    int ar = lca(a, r);
    int br = lca(b, r);
    return (ar == r && br == c) || (br == r && ar == c);
}

//next node on the path from a to b
int nextNode(int a, int b)
{
    int c = lca(a, b);
    if (a == c)
        return jump(b, h[b]-h[a]-1);
    else
        return spt[0][a];
}

bool handleQuery(vector<int> &a, int ADD_EDGES)
{
    st[1].lazymod = 1;
    pushdown(1, cc, 1);
    for (int x = 0; x < a.size()-1; x++)
    {
        int u = a[x], v = a[x+1];
        if (x < a.size()-2)
            v = nextNode(v, u);
        pathUpdate(u, v, 1);
    }
    if (st[1].ma > ADD_EDGES+1)
        return false;
    if (st[1].ma == 1)
        return true;
    int chk = revmp[st[1].id];
    for (int x = 0; x < a.size()-1; x++)
    {
        int u = a[x], v = a[x+1];
        if (onPath(u, v, chk))
        {
            u = nextNode(u, v);
            if (u == v)
                continue;
            v = nextNode(v, u);
            pathUpdate(u, v, -1);
            if (st[1].ma == 1)
                return true;
            else if (ADD_EDGES == 2 && st[1].ma <= ADD_EDGES)
            {
                int chk2 = revmp[st[1].id];
                for (int y = 0; y < a.size()-1; y++)
                {
                    int uu = a[y], vv = a[y+1];
                    if (x != y && onPath(uu, vv, chk2))
                    {
                        uu = nextNode(uu, vv);
                        if (uu == vv)
                            continue;
                        vv = nextNode(vv, uu);
                        pathUpdate(uu, vv, -1);
                        if (st[1].ma == 1)
                            return true;
                        pathUpdate(uu, vv, 1);
                    }
                }
            }
            pathUpdate(u, v, 1);
        }
    }
    return false;
}

int main()
{
    int q, a, b, k, v;
    assert(scanf("%i%i", &n, &q) == 2);
    assert(3 <= n && n <= 100000);
    assert(1 <= q && q <= 100000);
    for (int x = 1; x < n; x++)
    {
        assert(scanf("%i%i", &a, &b) == 2);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        assert(a != b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    dfs2(1, 1);
    build(1, cc, 1);
    build();
    while (q--)
    {
        assert(scanf("%i%i", &v, &k) == 2);
        assert(0 <= v && v <= 2);
        assert(3 <= k && k <= 20);
        vector<int> u(k);
        for (auto &x : u)
        {
            assert(scanf("%i", &x) == 1);
            assert(1 <= x && x <= n);
        }
        printf("%i\n", handleQuery(u, v));
    }
}
