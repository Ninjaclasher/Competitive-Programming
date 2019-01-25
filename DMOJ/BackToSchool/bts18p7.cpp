#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100020, MAXQ = 100001;

struct qquery
{
    int a, b, k;
};

int pop[MAXN], sz[MAXN], h[MAXN], par[MAXN], hev[MAXN], top[MAXN], mp[MAXN], revmp[MAXN], arr[MAXN];
int ans[MAXQ];

vector<int> pp(MAXN), rnk(MAXN, 1);
int st[MAXN<<2];
vector<vector<int>> adj(MAXN);
vector<pair<int,int>> ed(MAXN);
int cc = 1;

void dfs(int u, int p)
{
    sz[u] = 1;
    par[u] = p;
    h[u] = h[p]+1;
    int ma = 0;
    for (auto &x : adj[u])
    {
        if (x ^ p)
        {
            dfs(x, u);
            if (sz[x] > ma)
                ma = sz[x], hev[u] = x;
            sz[u] += sz[x];
        }
    }
}

void dfs2(int u, int p)
{
    if (hev[p] ^ u)
        top[u] = u;
    else
        top[u] = top[p];
    mp[u] = cc++;
    revmp[mp[u]] = u;
    arr[mp[u]] = pop[u];
    if (hev[u])
        dfs2(hev[u], u);
    for (auto &x : adj[u])
        if (x ^ hev[u] && x ^ p)
            dfs2(x, u);
}

int build(int l, int r, int v)
{
    if(l == r)
        return st[v] = arr[l];
    int m = l+r>>1;
    return st[v] = max(build(l, m, v<<1), build(m+1, r, v<<1|1));
}

int query(int l, int r, int v, int li, int ri, int k, int d)
{
    if (l > ri || r < li || st[v] < k)
        return -1;
    if (l == r)
        return l;
    int m = l+r>>1;
    if (!d)
    {
        int a = query(l, m, v<<1, li, ri, k, d);
        if (~a)
            return a;
        return query(m+1, r, v<<1|1, li, ri, k, d);
    }
    else
    {
        int b = query(m+1, r, v<<1|1, li, ri, k, d);
        if (~b)
            return b;
        return query(l, m, v<<1, li, ri, k, d);
    }
    abort();
}

int path(int a, int b, int k)
{
    int bside = -1;
    while (top[a] != top[b])
    {
        if (h[top[a]] >= h[top[b]])
        {
            int ret = query(1, cc-1, 1, mp[top[a]], mp[a], k, 1);
            a = par[top[a]];
            if (~ret)
                return revmp[ret];
        }
        else
        {
            int ret = query(1, cc-1, 1, mp[top[b]], mp[b], k, 0);
            b = par[top[b]];
            if (~ret)
                bside = revmp[ret];
        }
    }
    int aa = h[a] < h[b] ? a : b;
    int bb = h[a] < h[b] ? b : a;
    int ret = query(1, cc-1, 1, mp[aa], mp[bb], k, h[a] > h[b]);
    if (~ret)
        return revmp[ret];
    return bside;
}

int find(int n)
{
    if (n ^ pp[n]) pp[n] = find(pp[n]);
    return pp[n];
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        abort();
    if (rnk[a] > rnk[b])
        pp[b] = a;
    else
        pp[a] = b;
    if (rnk[a] == rnk[b])
        rnk[b]++;
}

int main()
{
    iota(pp.begin(), pp.end(), 0);
    int n, q, r, a, b, c;
    scanf("%i%i%i", &n, &q, &r);
    assert(1 <= n && n <= 100000);
    assert(1 <= q && q <= 100000);
    for (int x = 1; x <= n; x++)
        scanf("%i", &pop[x]), assert(0 <= pop[x] && pop[x] <= 1000000000);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        assert(a != b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        ed[x] = {a, b};
    }
    dfs(1, 1);
    dfs2(1, 1);
    build(1, cc-1, 1);
    vector<pair<int,int>> rr(r);
    for (auto &x : rr)
    {
        scanf("%i%i", &x.first, &x.second);
        assert(1 <= x.first && x.first <= q);
        assert(1 <= x.second && x.second < n);
    }
    sort(rr.begin(), rr.end(), [](auto &aa, auto &bb) {return aa.second < bb.second;});
    for (int x = 1, ii = 0; x < n; x++)
    {
        if (ii < rr.size() && rr[ii].second == x)
            ii++;
        else
            merge(ed[x].first, ed[x].second);
    }
    vector<qquery> qq(q);
    for (auto &x : qq)
    {
        scanf("%i%i%i", &x.a, &x.b, &x.k);
        assert(1 <= x.a && x.a <= n);
        assert(1 <= x.b && x.b <= n);
        assert(0 <= x.k && x.k <= 1000000000);
    }
    sort(rr.begin(), rr.end());
    for (int x = q-1, jj = rr.size()-1; x >= 0; x--)
    {
        auto &cur = qq[x];
        while (jj >= 0 && rr[jj].first == x+1)
            merge(ed[rr[jj].second].first, ed[rr[jj].second].second), jj--;
        if (find(cur.a) ^ find(cur.b))
            ans[x] = -1;
        else
            ans[x] = path(cur.a, cur.b, cur.k);
    }
    for (int x = 0; x < q; x++)
        printf("%i\n", ans[x]);
}
