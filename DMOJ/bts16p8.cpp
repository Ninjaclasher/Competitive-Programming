#include <bits/stdc++.h>

using namespace std;

struct node
{
    int v, lazyv, lazyh;
};

struct upd
{
    int s, l, w;
};

map<int, int> mp;
vector<int> revmp(2000001);
vector<node> st(6000000);
long long ans = 0;

static inline void push(int l, int r, int v)
{
    if (!st[v].lazyh && !st[v].lazyv)
        return;
    if (l == r)
        ans += (st[v].lazyv - st[v].v - st[v].lazyh) * (long long)(!l ? revmp[l] : revmp[l] - revmp[l-1]);
    else
    {
        st[v<<1].lazyv = st[v].lazyv;
        st[v<<1].lazyh += st[v].lazyh;
        st[v<<1|1].lazyv = st[v].lazyv;
        st[v<<1|1].lazyh += st[v].lazyh;    
    }
    st[v].v = st[v].lazyv;
    st[v].lazyv = st[v].lazyh = 0;
}

int query(int l, int r, int v, int li, int ri)
{
    push(l, r, v);
    if (r < li || l > ri)
        return 0;
    if (l >= li && r <= ri)
        return st[v].v;
    int m = l+r>>1;
    return max(query(l, m, v<<1, li, ri), query(m+1, r, v<<1|1, li, ri));
}

int update(int l, int r, int v, int li, int ri, int val, int h)
{
    push(l, r, v);
    if (r < li || l > ri)
        return st[v].v;
    if (l >= li && r <= ri)
    {
        st[v].lazyh = h;
        st[v].lazyv = val;
        push(l, r, v);
        return val;
    }
    int m = l+r>>1;
    return st[v].v = max(update(l, m, v<<1, li, ri, val, h), update(m+1, r, v<<1|1, li, ri, val, h));
}

void push_down(int l, int r, int v)
{
    push(l, r, v);
    if (l == r)
        return;
    int m = l+r>>1;
    push_down(l, m, v<<1);
    push_down(m+1, r, v<<1|1);
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> xv;
    vector<upd> up(n);
    for (auto &x : up)
    {
        scanf("%i%i%i", &x.s, &x.l, &x.w);
        xv.push_back(x.s), xv.push_back(x.s+x.l-1);
        xv.push_back(x.s-1);
    }
    sort(xv.begin(), xv.end());
    xv.erase(unique(xv.begin(), xv.end()), xv.end());
    for (int x = 0; x < xv.size(); x++)
        mp[xv[x]] = x, revmp[x] = xv[x];
    int cnt = 0;
    for (auto &x: up)
    {
        int s = mp[x.s], e = mp[x.s+x.l-1];
        int curma = query(0, 2000000, 1, s, e);
        update(0, 2000000, 1, s, e, curma+x.w, x.w);
    }
    push_down(0, 2000000, 1);
    printf("%lli\n", ans%1000000007);
}
