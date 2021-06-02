#include <bits/stdc++.h>

using namespace std;

struct node
{
    int mi;
    long long lazy;
};

node st[5000000];
vector<int> arr(1000005, INT_MAX);

int build(int l, int r, int v)
{
    if (l == r)
        return st[v].mi = arr[l];
    int m = l+r>>1;
    return st[v].mi = min(build(l, m, v<<1), build(m+1, r, v<<1|1));
}

static inline void pushdown(int l, int r, int v)
{
    if (st[v].lazy)
    {
        st[v].mi -= min((long long)st[v].mi, st[v].lazy);
        if (l ^ r)
        {
            st[v<<1].lazy += st[v].lazy;
            st[v<<1|1].lazy += st[v].lazy;
        }
        st[v].lazy = 0;
    }
}

int run(int l, int r, int v, int li, int ri, int c)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return INT_MAX;
    if (l >= li && r <= ri)
    {
        st[v].lazy = c;
        pushdown(l, r, v);
        return st[v].mi;
    }
    int m = l+r>>1;
    int ans = min(run(l, m, v<<1, li, ri, c), run(m+1, r, v<<1|1, li, ri, c));
    st[v].mi = min(st[v<<1].mi, st[v<<1|1].mi);
    return ans;
}

int main()
{
    int n, q, l, r, c;
    scanf("%i%i", &n, &q);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    build(1, n, 1);
    while(q--)
    {
        scanf("%i%i%i", &l, &r, &c);
        int ans = run(1, n, 1, l, r, c);
        printf("%i %i\n", ans, st[1].mi);
    }
}
