#include <bits/stdc++.h>

using namespace std;

struct node
{
    int lazy = 0;
    int sufl = 0, sufs = 0, prel = 0, pres = 0, maxl = 0, maxs = 0;
} st[400000];

void getMax(int &ml, int &ms, int cl, int cs)
{
    if (cl > ml || (cl == ml && cs < ms))
        ml = cl, ms = cs;
}

void pushup(int l, int r, int v)
{
    st[v].prel = st[v<<1].prel;
    st[v].pres = st[v<<1].pres;
    int m = l+r>>1;
    if (st[v<<1].prel == m-l+1)
        st[v].prel += st[v<<1|1].prel;
    st[v].sufl = st[v<<1|1].sufl;
    st[v].sufs = st[v<<1|1].sufs;
    if (st[v<<1|1].sufl == r-m)
    {
        st[v].sufl += st[v<<1].sufl;
        st[v].sufs = st[v<<1].sufs;
    }
    int &ml = st[v].maxl, &ms = st[v].maxs;
    ml = ms = 0;
    getMax(ml, ms, st[v<<1].maxl, st[v<<1].maxs);
    getMax(ml, ms, st[v<<1|1].maxl, st[v<<1|1].maxs);
    getMax(ml, ms, st[v].sufl, st[v].sufs);
    getMax(ml, ms, st[v].prel, st[v].pres);
    getMax(ml, ms, st[v<<1].sufl, st[v<<1].sufs);
    getMax(ml, ms, st[v<<1|1].prel, st[v<<1|1].pres);
    getMax(ml, ms, st[v<<1].sufl+st[v<<1|1].prel, st[v<<1].sufs);
}

void pushdown(int l, int r, int v)
{
    if (~st[v].lazy)
    {
        if (!st[v].lazy)
        {
            st[v].sufl = st[v].prel = st[v].maxl = 0;
            st[v].pres = st[v].maxs = l;
            st[v].sufs = r;
        }
        else
        {
            st[v].sufl = st[v].prel = st[v].maxl = (r-l+1);
            st[v].sufs = st[v].pres = st[v].maxs = l;
        }
        if (l ^ r)
            st[v<<1].lazy = st[v<<1|1].lazy = st[v].lazy;
        st[v].lazy = -1;
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
    pushup(l, r, v);
}

int main()
{
    int n, q, t, a, b;
    scanf("%i%i", &n, &q);
    while (q--)
    {
        scanf("%i", &t);
        if (t == 0)
        {
            scanf("%i%i", &a, &b);
            update(1, n, 1, a, b, 0);
        }
        else if (t == 1)
        {
            scanf("%i%i", &a, &b);
            update(1, n, 1, a, b, 1);
        }
        else
            update(1, n, 1, st[1].maxs, st[1].maxs+st[1].maxl, 0);
        if (t != 2)
            printf("%i\n", st[1].maxl);
    }
}

