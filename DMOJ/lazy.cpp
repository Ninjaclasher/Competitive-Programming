#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long mi, lazyInc = 0;
    int lazyMod = 0;
};

const int MAXN = 100005;

node st[MAXN<<2];
int arr[MAXN];

void pullup(int l, int r, int v)
{
    assert(l < r);
    st[v].mi = min(st[v<<1].mi, st[v<<1|1].mi);
}

void pushdown(int l, int r, int v)
{
    if (st[v].lazyMod)
    {
        st[v].mi = st[v].lazyMod;
        if (l != r)
        {
            st[v<<1].lazyMod = st[v<<1|1].lazyMod = st[v].lazyMod;
            st[v<<1].lazyInc = st[v<<1|1].lazyInc = 0;
        }
        st[v].lazyMod = 0;
    }
    if (st[v].lazyInc)
    {
        st[v].mi += st[v].lazyInc;
        if (l != r)
        {
            st[v<<1].lazyInc += st[v].lazyInc;
            st[v<<1|1].lazyInc += st[v].lazyInc;
        }
        st[v].lazyInc = 0;
    }
}

void build(int l, int r, int v)
{
    if (l == r)
    {
        st[v].mi = arr[l];
        return;
    }
    int m = l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    pullup(l, r, v);
}

void updateMod(int l, int r, int v, int li, int ri, int val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return;
    if (l >= li && r <= ri)
    {
        st[v].lazyMod = val;
        pushdown(l, r, v);
        return;
    }
    int m = l+r>>1;
    updateMod(l, m, v<<1, li, ri, val);
    updateMod(m+1, r, v<<1|1, li, ri, val);
    pullup(l, r, v);
}

void updateInc(int l, int r, int v, int li, int ri, int val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return;
    if (l >= li && r <= ri)
    {
        st[v].lazyInc = val;
        pushdown(l, r, v);
        return;
    }
    int m = l+r>>1;
    updateInc(l, m, v<<1, li, ri, val);
    updateInc(m+1, r, v<<1|1, li, ri, val);
    pullup(l, r, v);
}

long long query(int l, int r, int v, int li, int ri)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return LONG_MAX;
    if (l >= li && r <= ri)
        return st[v].mi;
    int m = l+r>>1;
    return min(query(l, m, v<<1, li, ri), query(m+1, r, v<<1|1, li, ri));
}

int main()
{
    int n, q;
    scanf("%i%i", &n, &q);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    build(1, n, 1);
    while (q--)
    {
        int t, l, r, v;
        scanf("%i%i%i", &t, &l, &r);
        if (t == 1)
        {
            scanf("%i", &v);
            updateInc(1, n, 1, l, r, v);
        }
        else if (t == 2)
        {
            scanf("%i", &v);
            updateMod(1, n, 1, l, r, v);
        }
        else
            printf("%lli\n", query(1, n, 1, l, r));
    }
}
