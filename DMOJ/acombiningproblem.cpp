#include <bits/stdc++.h>

using namespace std;

struct node
{
    int sum = 0;
    int lazy;  
};

const int MAXN = 100005;

node st[MAXN<<2];
int bit[MAXN];

void pushdown(int l, int r, int v)
{
    if (~st[v].lazy)
    {
        st[v].sum = (r-l+1)*st[v].lazy;
        if (l ^ r)
            st[v<<1].lazy = st[v<<1|1].lazy = st[v].lazy;
        st[v].lazy = -1;
    }
}

int build(int l, int r, int v)
{
    st[v].lazy = -1;
    if (l == r)
        return st[v].sum = 1;
    int m = l+r>>1;
    return st[v].sum = build(l, m, v<<1) + build(m+1, r, v<<1|1);
}

int update(int l, int r, int v, int li, int ri, int val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return st[v].sum;
    if (l >= li && r <= ri)
    {
        st[v].lazy = val;
        pushdown(l, r, v);
        return st[v].sum;
    }
    int m = l+r>>1;
    return st[v].sum = update(l, m, v<<1, li, ri, val) + update(m+1, r, v<<1|1, li, ri, val);
}

void update(int i, int v)
{
    for (; i < MAXN; i += i&-i)
        bit[i] += v;
}

int query(int i)
{
    int sum = 0;
    for (; i; i -= i&-i)
        sum += bit[i];
    return sum;
}

int query(int l, int r, int v, int k)
{
    if (l == r)
    {
        if (k != 1)
            abort();
        return l;
    }
    pushdown(l, r, v);
    int m = l+r>>1;
    pushdown(l, m, v<<1);
    pushdown(m+1, r, v<<1|1);
    if (k <= st[v<<1].sum)
        return query(l, m, v<<1, k);
    else
        return query(m+1, r, v<<1|1, k-st[v<<1].sum);
}

int n;

int getIdx(int i)
{
    if (!i)
        return 0;
    return query(1, n, 1, i);
}

int main()
{
    int q, a, t, l, r;
    scanf("%i%i", &n, &q);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        update(x, a);
    }
    build(1, n, 1);
    int i, k;
    while (q--)
    {
        scanf("%i%i", &t, &i);
        if (t != 2)
            scanf("%i", &k);
        else
            k = 1;
        int sz = st[1].sum;
        i %= sz;
        if (!i)
            i = sz;
        l = getIdx(i-1)+1;
        k %= sz-i+1;
        if (!k)
            k = sz-i+1;
        r = getIdx(i+k-1);
        assert(1 <= l && l <= r && r <= n);
        if (t == 1)
        {
            update(1, n, 1, l, r, 0);
            update(1, n, 1, r, r, 1);
        }
        else if (t == 2)
        {
            update(1, n, 1, l, r, 1);
        }
        else if (t == 3)
        {
            printf("%i\n", query(r)-query(l-1));
        }
    }
}
