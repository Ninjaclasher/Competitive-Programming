#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long sum, suf, pre, mid;
};

vector<node> st(300005);
vector<long long> arr(100005, LONG_MIN);

node run(node ll, node rr)
{
    if (ll.sum == LONG_MIN)
        return rr;
    else if (rr.sum == LONG_MIN)
        return ll;
    node cur = {ll.sum+rr.sum, max(rr.suf, rr.sum+ll.suf), max(ll.pre, ll.sum+rr.pre), 0};
    cur.mid = max(max(cur.sum, max(cur.pre, cur.suf)), max(ll.suf+rr.pre, max(ll.mid, rr.mid)));
    return cur;
}

node update(int l, int r, int i, int x, int v)
{
    if (l > x || r < x)
        return st[i];
    if (l == r)
        return st[i] = {v, v, v, v};
    int m = l+r>>1;
    return st[i] = run(update(l, m, i<<1, x, v), update(m+1, r, i<<1|1, x, v));
}

node query(int l, int r, int i, int li, int ri)
{
    if (l > ri || r < li)
        return {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    if (l >= li && r <= ri)
        return st[i];
    int m = l+r>>1;
    return run(query(l, m, i<<1, li, ri), query(m+1, r, i<<1|1, li, ri));
}

node build(int l, int r, int i)
{
    if (l == r)
        return st[i] = {arr[l], arr[l], arr[l], arr[l]};
    int m = l+r>>1;
    return st[i] = run(build(l, m, i<<1), build(m+1, r, i<<1|1));
}

int main()
{
    int n, q, a, b;
    char t;
    scanf("%i%i", &n, &q);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]);
    build(1, 100001, 1);
    while (q--)
    {
        scanf(" %c%i%i", &t, &a, &b);
        if (t == 'S')
            update(1, 100001, 1, a, b);
        else
        {
            node ret = query(1, 100001, 1, a, b);
            printf("%lli\n", max(max(ret.sum, ret.mid), max(ret.suf, ret.pre)));
        }
    }
}
