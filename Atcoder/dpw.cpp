#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

struct node
{
    long long ma, lazy;
};

struct event 
{
    int l, r, a;
};

node st[MAXN<<2];

void pushdown(int l, int r, int v)
{
    if (st[v].lazy)
    {
        st[v].ma += st[v].lazy;
        if (l ^ r)
            st[v<<1].lazy += st[v].lazy, st[v<<1|1].lazy += st[v].lazy;
        st[v].lazy = 0;
    }
}

long long update(int l, int r, int v, int li, int ri, long long val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return st[v].ma;
    if (l >= li && r <= ri)
    {
        st[v].lazy = val;
        pushdown(l, r, v);
        return st[v].ma;
    }
    int m = l+r>>1;
    return st[v].ma = max(update(l, m, v<<1, li, ri, val), update(m+1, r, v<<1|1, li, ri, val));
}

long long query(int l, int r, int v, int li, int ri)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return LONG_MIN;
    if (l >= li && r <= ri)
        return st[v].ma;
    int m = l+r>>1;
    return max(query(l, m, v<<1, li, ri), query(m+1, r, v<<1|1, li, ri));
}

void update2(int l, int r, int v, int i, long long val)
{
    update(l, r, v, i, i, val - query(l, r, v, i, i));
}

int main()
{
    int n, m, a, b, c;
    scanf("%i%i", &n, &m);
    vector<vector<event>> ev(n+1);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        ev[b].push_back({a, b, c});
    }
    for (int x = 1; x <= n; x++)
    {
        update2(0, n, 1, x, query(1, n, 1, 0, x));
        for (auto &y : ev[x])
            update(0, n, 1, y.l, y.r, y.a);
    }
    printf("%lli\n", query(0, n, 1, 0, n));
}
