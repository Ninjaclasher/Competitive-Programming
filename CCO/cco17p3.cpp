#include <bits/stdc++.h>

using namespace std;

vector<long long> bit(600005);
set<long long> xx;

struct event
{
    long long x, y, yy, t;
    friend bool operator<(event &a, event &b)
    {
        return a.x < b.x;
    }
};

struct qq
{
    long long x, y, i;
    friend bool operator<(qq &a, qq &b)
    {
        return a.x < b.x;
    }
};

inline long long flip(long long xx)
{
    long long ret = 0;
    for (int x = 0; x < 63; x++)
        ret = (ret<<1)|(xx&1), xx>>=1;
    return ret;
}

void update(int i, long long v)
{
    for (; i < bit.size(); i += i&-i)
        bit[i] += v;
}

long long query(int i)
{
    long long s = 0;
    for (; i > 0; i -= i&-i)
        s += bit[i];
    return s;
}

int main()
{
    vector<event> ev;
    map<long long, int> mp;
    int n, q;
    long long a, b, c;
    scanf("%i%i", &n, &q);
    vector<qq> qu(q);
    vector<long long> ans(q);
    for (int x = 0; x < n; x++)
    {
        scanf("%lli%lli%lli", &a, &b, &c);
        a = flip(a), b = flip(b);
        long long aa = a&-a, bb = b&-b;
        ev.push_back({a-aa, b-bb, b+bb-1, c});
        ev.push_back({a+aa-1, b-bb, b+bb-1, -c});
        xx.insert(b-bb), xx.insert(b+bb-1);
    }
    for (int x = 0; x < q; x++)
    {
        scanf("%lli%lli", &a, &b);
        qu[x] = {flip(a), flip(b), x};
        xx.insert(qu[x].y);
    }
    sort(ev.begin(), ev.end());
    sort(qu.begin(), qu.end());
    c = 0;
    for (auto x : xx)
        mp[x] = ++c;
    for (int x = 0, y = 0; y < q && x < ev.size(); x++)
    {
        for (;y < q && ev[x].x >= qu[y].x; y++)
            ans[qu[y].i] = query(mp[qu[y].y]-1);
        update(mp[ev[x].y], ev[x].t), update(mp[ev[x].yy], -ev[x].t);
    }
    for (auto &x : ans)
        printf("%lli\n", x);
}
