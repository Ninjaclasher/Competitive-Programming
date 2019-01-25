#include <bits/stdc++.h>

using namespace std;

vector<int> mi(200000, INT_MAX), ma(200000, INT_MIN), arr(200000);

pair<int,int> build(int l, int r, int v)
{
    if (l ==r)
        return {mi[v] = arr[l], ma[v] = arr[l]};
    int m = l+r>>1;
    pair<int,int> a = build(l, m, v<<1), b = build(m+1, r, v<<1|1);
    return {mi[v] = min(a.first, b.first), ma[v] = max(a.second, b.second)};
}

pair<int,int> query(int l, int r, int v, int li, int ri)
{
    if (li > r || ri < l)
        return {INT_MAX, INT_MIN};
    if (l >= li && r <= ri)
        return {mi[v], ma[v]};
    int m = l+r>>1;
    pair<int,int> a = query(l, m, v<<1, li, ri), b = query(m+1, r, v<<1|1, li, ri);
    return {min(a.first,b.first), max(a.second,b.second)};
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
        int a, b;
        scanf("%i%i", &a, &b);
        pair<int,int> aa = query(1, n, 1, a, b);
        printf("%i\n", aa.second-aa.first);
    }
}
