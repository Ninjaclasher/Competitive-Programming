#include <bits/stdc++.h>

using namespace std;

struct node
{
    int sum, lazy = INT_MAX;
} st[24][400000];

int arr[400000];

void pushdown(int l, int r, int v, int i)
{
    if (st[i][v].lazy != INT_MAX)
    {
        st[i][v].sum = (r-l+1) * st[i][v].lazy;
        if (l ^ r)
            st[i][v<<1].lazy = st[i][v<<1|1].lazy = st[i][v].lazy;
        st[i][v].lazy = INT_MAX;
    }
}

int build(int l, int r, int v, int i)
{
    if (l == r)
        return st[i][v].sum = (arr[l] == i);
    int m = l+r>>1;
    return st[i][v].sum = build(l, m, v<<1, i) + build(m+1, r, v<<1|1, i);
}

int query(int l, int r, int v, int li, int ri, int i)
{
    pushdown(l, r, v, i);
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
    {
        st[i][v].lazy = 0;
        int sum = st[i][v].sum;
        pushdown(l, r, v, i);
        return sum;
    }
    int m = l+r>>1;
    int sum = query(l, m, v<<1, li, ri, i) + query(m+1, r, v<<1|1, li, ri, i);
    st[i][v].sum = st[i][v<<1].sum + st[i][v<<1|1].sum;
    return sum;
}

int update(int l, int r, int v, int li, int ri, int val, int i)
{
    pushdown(l,r, v, i);
    if (l > ri || r < li)
        return st[i][v].sum;
    if (l >= li && r <= ri)
    {
        st[i][v].lazy = val;
        pushdown(l, r, v, i);
        return st[i][v].sum;
    }
    int m = l+r>>1;
    return st[i][v].sum = update(l, m, v<<1, li, ri, val, i) + update(m+1, r, v<<1|1, li, ri, val, i);
}

int main()
{
    int n, m, k;
    scanf("%i%i%i", &n, &m, &k);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    for (int x = 1; x <= k; x++)
        build(1, n, 1, x);
    int l, r;
    vector<int> p(k+1);
    while (m--)
    {
        vector<int> val(k+1);
        scanf("%i%i", &l, &r);
        for (int x = 1; x <= k; x++)
            scanf("%i", &p[x]), val[x] = query(1, n, 1, l, r, x);
        int cur = l;
        for (int x = 1; x <= k; x++)
        {
            update(1, n, 1, cur, cur+val[p[x]]-1, 1, p[x]);
            cur += val[p[x]];
        }
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= k; y++)
        {
            if (query(1, n, 1, x, x, y) == 1)
            {
                printf("%i ", y);
                goto nxt;
            }
        }
nxt:;
    }
}

