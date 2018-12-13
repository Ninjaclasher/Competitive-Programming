#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long lazy, lazyadd, sum;
} st[3000005];

void pushdown(int l, int r, int v)
{
    int m = l+r>>1;
    if (st[v].lazy)
    {
        int len = r-l+1;
        st[v].sum += (len+1)*len/2 * st[v].lazy;
        st[v].sum += st[v].lazyadd;
        if (l ^ r)
        {
            st[v<<1].lazy += st[v].lazy;
            st[v<<1].lazyadd += st[v].lazyadd;
            st[v<<1|1].lazy += st[v].lazy;
            st[v<<1|1].lazyadd += st[v].lazyadd + (m-l+1)*st[v].lazy;
        }
        st[v].lazy = 0, st[v].lazyadd = 0;
    }
}

void update(int l, int r, int v, int li, int ri, int val, int lazyadd=0)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return;
    if (l >= li && r <= ri)
    {
        st[v].lazy = val;
        st[v].lazyadd = lazyadd;
        pushdown(l, r, v);
        return;
    }
    int m = l+r>>1;
    update(l, m, v<<1, li, ri, val, lazyadd);
    update(m+1, r, v<<1|1, li, ri, val, lazyadd + (max(0, m-li+1) * val));
    st[v].sum = st[v<<1].sum + st[v<<1|1].sum;
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
    int n, q, l, r, a, t;
    scanf("%i%i", &n, &q);
    while (q--)
    {
        scanf("%i%i%i", &t, &l, &r);
        if (t == 1)
        {
            scanf("%i", &a);
            update(1, n, 1, l, r, a);
        }
        else
            printf("%lli\n", query(1, n, 1, l, r));
    }
}
