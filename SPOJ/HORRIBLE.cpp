#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long sum, lazy;
};

const int MAXN = 100005;

node st[MAXN<<2];

void pushdown(int l, int r, int v)
{
    if (st[v].lazy)
    {
        st[v].sum += st[v].lazy * (r-l+1);
        if (l ^ r)
            st[v<<1].lazy += st[v].lazy, st[v<<1|1].lazy += st[v].lazy;
        st[v].lazy = 0;
    }
}

long long update(int l, int r, int v, int li, int ri, int val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return st[v].sum;
    if (l >= li && r <= ri)
    {
        st[v].lazy += val;
        pushdown(l, r, v);
        return st[v].sum;
    }
    int m = l+r>>1;
    return st[v].sum = update(l, m, v<<1, li, ri, val) + update(m+1, r, v<<1|1, li, ri, val);
}

long long query(int l, int r, int v, int li, int ri)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
        return st[v].sum;
    int m = l+r>>1;
    return query(l, m, v<<1, li, ri) + query(m+1, r, v<<1|1, li, ri);
}

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        memset(st, 0, sizeof st);
        int n, q, a, b, c, op;
        scanf("%i%i", &n, &q);
        while (q--)
        {
            scanf("%i%i%i", &op, &a, &b);
            if (op == 0)
            {
                scanf("%i", &c);
                update(1, n, 1, a, b, c);
            }
            else
                printf("%lli\n", query(1, n, 1, a, b));
        }
    }
}
