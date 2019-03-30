#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int st[MAXN<<2], arr[MAXN];

int build(int l, int r, int v)
{
    if (l == r)
        return st[v] = arr[l];
    int m = l+r>>1;
    return st[v] = build(l, m, v<<1) | build(m+1, r, v<<1|1);
}

int update(int l, int r, int v, int i, int val)
{
    if (l > i || r < i)
        return st[v];
    if (l == r)
        return st[v] = arr[l] = val;
    int m = l+r>>1;
    return st[v] = update(l, m, v<<1, i, val) | update(m+1, r, v<<1|1, i, val);
}

int query(int l,int r, int v, int li, int ri)
{
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
        return st[v];
    int m = l+r>>1;
    return query(l, m, v<<1, li, ri) | query(m+1, r, v<<1|1, li, ri);
}


int main()
{
    int n, q;
    scanf("%i%i", &n, &q);
    set<int> neg_idx;
    multiset<int> values;
    int cur = 0, pidx = 0;
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &arr[x]);
        if (arr[x] < 0)
        {
            if (pidx)
                values.insert(cur);
            neg_idx.insert(x);
            cur = 0;
            pidx = 0;
        }
        else
        {
            cur |= arr[x];
            pidx = 1;
        }
    }
    if (pidx)
        values.insert(cur);
    neg_idx.insert(0);
    neg_idx.insert(n+1);
    build(1, n, 1);
    while (q--)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        bool aa = arr[a] < 0;
        bool bb = b < 0;
        if (aa && bb)
        {
            update(1, n, 1, a, b);
        }
        else if (aa && !bb)
        {
            auto it = neg_idx.find(a);
            if (it == neg_idx.end())
                abort();
            auto it2 = it;
            int pe = *(--it2)+1; 
            it2 = it;
            int ne = *(++it2)-1;
            if (pe != a)
                values.erase(values.find(query(1, n, 1, pe, a-1)));
            if (ne != a)
                values.erase(values.find(query(1, n, 1, a+1, ne)));
            neg_idx.erase(it);
            update(1, n, 1, a, b);
            values.insert(query(1, n, 1, pe, ne));
        }
        else if (!aa && bb)
        {
            auto it = neg_idx.lower_bound(a);
            int ne = *it - 1;
            int pe = *(--it) + 1;
            values.erase(values.find(query(1, n, 1, pe, ne)));
            if (a != pe)
                values.insert(query(1, n, 1, pe, a-1));
            if (a != ne)
                values.insert(query(1, n, 1, a+1, ne));
            neg_idx.insert(a);
            update(1, n, 1, a, b);
        }
        else
        {
            auto it = neg_idx.lower_bound(a);
            int ne = *it-1;
            int pe = *(--it) + 1;
            values.erase(values.find(query(1, n, 1, pe, ne)));
            update(1, n, 1, a, b);
            values.insert(query(1, n, 1, pe, ne));
        }
        if (!values.empty())
        {
            auto it = values.end();
            --it;
            printf("%i\n", *it);
        }
        else
        {
            printf("%i\n", query(1, n, 1, 1, n));
        }
    }
}
