#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;

vector<int> st(MAXN<<3), bit(MAXN<<2);

int update(int l, int r, int v, int i, int val)
{
    if (l > i || r < i)
        return st[v];
    if (l == r)
        return st[v] = max(st[v], val);
    int m = l+r>>1;
    return st[v] = max(update(l, m, v<<1, i, val), update(m+1, r, v<<1|1, i, val));
}

int query(int l, int r, int v, int li, int ri)
{
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
        return st[v];
    int m = l+r>>1;
    return max(query(l, m, v<<1, li, ri), query(m+1, r, v<<1|1, li, ri));
}

void update(int i, int v)
{
    for (; i < bit.size(); i += i&-i)
        bit[i] += v;
}

int query(int i)
{
    int sum = 0;
    for (; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<pair<int,int>> po(n);
    vector<pair<int,int>> ev(m);
    set<int> yy;
    map<int,int> mp;
    for (auto &x : po)
        scanf("%i%i", &x.first, &x.second), yy.insert(x.second);
    sort(po.begin(), po.end());
    for (auto &x : ev)
        scanf("%i%i", &x.first, &x.second), yy.insert(x.second);
    sort(ev.begin(), ev.end());
    int c = 0;
    for (auto &y : yy)
        mp[y] = ++c;
    int mi = INT_MAX;
    for (int y = 0, i = 0; y < ev.size(); y++)
    {
        auto &x = ev[y];
        while (i < po.size() && po[i].first <= x.first)
            update(mp[po[i].second], 1), mi = min(mi, po[i].second), ++i;
        vector<int> vl;
        for (; y < ev.size() && ev[y].first == x.first; y++)
            if (mi <= ev[y].second)
                vl.push_back(query(1, c, 1, mp[ev[y].second]+1, c) + query(mp[ev[y].second]));
        --y;
        for (auto &z : vl)
            update(1, c, 1, mp[mi], z);
    }
    printf("%i\n", st[1]);
}
