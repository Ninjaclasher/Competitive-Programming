#include <bits/stdc++.h>

using namespace std;

struct node
{
    int ma, lazy = 0;
};

const int MAXN = 100010;

node st[MAXN*6];

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

void update(int l, int r, int v, int li, int ri, int val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return;
    if (l >= li && r <= ri)
    {
        st[v].lazy += val;
        pushdown(l, r, v);
        return;
    }
    int m = l+r>>1;
    update(l, m, v<<1, li, ri, val);
    update(m+1, r, v<<1|1, li, ri, val);
    st[v].ma = max(st[v<<1].ma, st[v<<1|1].ma);
}

int main()
{
    int n, ma = 0;
    scanf("%i", &n);
    vector<int> arr(n+1);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    for (int x = 1; x <= n; x++)
        update(1, n, 1, 1, arr[x], (x <= (n>>1) ? -1 : 1));
    for (int x = n; x >= 0; x--)
    {
        if (!(x&1))
        {
            if (st[1].ma <= 0)
                return 0 * printf("%i\n", x>>1);
            update(1, n, 1, 1, arr[x>>1], 2);
        }
        update(1, n, 1, 1, arr[x], -1);
    }
}

