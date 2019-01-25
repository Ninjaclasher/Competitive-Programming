#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 200005;
 
vector<long long> st(MAXN<<2);
 
long long update(int l, int r, int v, int i, long long val)
{
    if (l > i || r < i)
        return st[v];
    if (l == r)
        return st[v] = max(val, st[v]);
    int m = l+r>>1;
    return st[v] = max(update(l, m, v<<1, i, val), update(m+1, r, v<<1|1, i, val));
}
 
long long query(int l, int r, int v, int li, int ri)
{
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
        return st[v];
    int m = l+r>>1;
    return max(query(l, m, v<<1, li, ri), query(m+1, r, v<<1|1, li, ri));
}
 
int main()
{
    int n;
    scanf("%i", &n);
    vector<int> h(n+1), a(n+1);
    for (int x = 1; x <= n; x++)
        scanf("%i", &h[x]);
    for (int x = 1; x <= n; x++)
        scanf("%i", &a[x]);
    for (int x = 1; x <= n; x++)
        update(1, n, 1, h[x], query(1, n, 1, 1, h[x]-1) + a[x]);
    printf("%lli\n", st[1]);
}
