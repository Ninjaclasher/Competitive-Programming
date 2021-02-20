#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150005;

int st[MAXN << 2], st2[MAXN << 2];

int merge(int a, int b)
{
    int _v = __gcd(a, b);
    if (!a || !b)
        return a ? a : b;
    return a * b / _v;
}

int update(int l, int r, int v, int i, int val)
{
    if (l > i || r < i)
        return st[v];
    if (l == r)
        return st[v] = val;
    int m = l+r>>1;
    return st[v] = merge(update(l, m, v<<1, i, val), update(m + 1, r, v<<1|1, i, val));
}

int build(int l, int r, int v, vector<int> &arr)
{
    if (l == r)
        return st2[v] = arr[l];
    int m = l+r>>1;
    return st2[v] = __gcd(build(l, m, v<<1, arr), build(m + 1, r, v<<1|1, arr));
}

int query2(int l, int r, int v, int li, int ri)
{
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
        return st2[v];
    int m = l+r>>1;
    return __gcd(query2(l, m, v<<1, li, ri), query2(m + 1, r, v<<1|1, li, ri));
}

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<vector<pair<int, int>>> constraints(n + 10);
    vector<pair<pair<int, int>, int>> full;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%i%i%i", &x, &y, &z);
        constraints[x].push_back({z, i});
        constraints[y + 1].push_back({0, i});
        full.push_back({{x, y}, z});
    }
    vector<int> a(n + 1);
    for (int x = 1; x <= n; x++)
    {
        for (auto &y : constraints[x])
            update(1, m, 1, y.second, y.first);
        a[x] = st[1];
        if (!a[x])
            a[x] = 1;
    }
    build(1, n, 1, a);
    for (auto &x : full)
        if (query2(1, n, 1, x.first.first, x.first.second) != x.second)
            return 0 * printf("Impossible\n");
    for (int x = 1; x <= n; x++)
        printf("%i%c", a[x], x == n ? '\n' : ' ');
}
