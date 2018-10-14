#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MAXN = 100005;

struct event
{
    int i, x, v;
    friend bool operator<(event &a, event &b)
    {
        return a.x < b.x;
    }
};

struct node
{
    int v, lazy;
};

node st[6*MAXN];
vector<pair<int,int>> seg;
int n, cnt = 0;

static inline __attribute__((always_inline)) void pushdown(int l, int r, int v)
{
    if (st[v].lazy)
    {
        st[v].v += st[v].lazy;
        if (l ^ r)
            st[v<<1].lazy += st[v].lazy, st[v<<1|1].lazy += st[v].lazy;
        st[v].lazy = 0;
    }
}

static void update(int l, int r, int v, int li, int ri, int val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return;
    if (l >= li && r <= ri)
    {
        st[v].lazy = val;
        pushdown(l, r, v);
        return;
    }
    int m = l+r>>1;
    update(l, m, v<<1, li, ri, val), update(m+1, r, v<<1|1, li, ri, val);
    st[v].v = max(st[v<<1].v, st[v<<1|1].v);
}

static inline __attribute__((always_inline)) void run(int &cur, event e)
{
    cur += e.v;
    update(1, cnt, 1, seg[e.i].first, seg[e.i].second, -e.v);
}

static inline __attribute__((always_inline)) void reset()
{
    memset(st, 0, sizeof st);
    cnt = 0;
}

int main()
{
    int t;
    scanf("%i", &t);
    for (int i = 1; i <= t; i++)
    {
        reset();
        int a, b;
        scan(n);
        seg.resize(n);
        vector<event> ev;
        vector<int> vv;
        map<int,int> mp;
        for (int x = 0; x < n; x++)
        {
            scan(a); scan(b);
            seg[x] = {a, b};
            ev.push_back({x, a, 1});
            ev.push_back({x, b+1, -1});
            vv.push_back(a);
            vv.push_back(b);
        }
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        for (auto &x : vv)
            mp[x] = ++cnt;
        for (auto &x : seg)
            update(1, cnt, 1, x.first = mp[x.first], x.second = mp[x.second], 1);
        sort(ev.begin(), ev.end());
        int ma = 0, cur = 0;
        for (int x = 0; x < ev.size(); x++)
        {
            run(cur, ev[x]);
            while (x+1 < ev.size() && ev[x+1].x == ev[x].x)
                run(cur, ev[++x]);
            ma = max(ma, cur + st[1].v);
        }
        printf("Case %i: %i\n", i, ma);
    }
}
