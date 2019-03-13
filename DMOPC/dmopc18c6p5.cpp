#include <bits/stdc++.h>

using namespace std;

struct node
{
    int ma, lazy;
};

const int MAXN = 500005;
const int MAXK = 100005;

node st[MAXN<<2];

void pushdown(int l, int r, int v)
{
    if (st[v].lazy)
    {
        st[v].ma += st[v].lazy;
        if (l ^ r)
            st[v<<1].lazy += st[v].lazy, st[v<<1|1].lazy += st[v].lazy;
        st[v].lazy = 0;
    }
}

int update(int l, int r, int v, int li, int ri, int val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return st[v].ma;
    if (l >= li && r <= ri)
    {
        st[v].lazy += val;
        pushdown(l, r, v);
        return st[v].ma;
    }
    int m = l+r>>1;
    return st[v].ma = max(update(l, m, v<<1, li, ri, val), update(m+1, r, v<<1|1, li, ri, val));
}

int query(int l, int r, int v, int li, int ri)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
        return st[v].ma;
    int m = l+r>>1;
    return max(query(l, m, v<<1, li, ri), query(m+1, r, v<<1|1, li, ri));
}

struct ev
{
    int y1, y2, t;
};

struct que
{
    int x1, y1, x2, y2;
};

vector<int> ans(MAXK);

int n, m, k, q, t;

void test(vector<que> queries, vector<pair<int,int>> &pos)
{
    memset(st, 0, sizeof st);
    vector<vector<ev>> quev(MAXN);
    vector<vector<pair<int,int>>> events(MAXN);
    map<int,int> mpx, mpy;
    vector<int> xx, yy;
    for (auto &x : queries)
    {
        xx.push_back(x.x1);
        xx.push_back(x.x2+1);
        yy.push_back(x.y1);
        yy.push_back(x.y2);
    }
    for (auto &x : pos)
    {
        xx.push_back(x.first);
        yy.push_back(x.second-t);
        yy.push_back(x.second+t);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());
    yy.erase(unique(yy.begin(), yy.end()), yy.end());
    for (int x = 0; x < xx.size(); x++)
        mpx[xx[x]] = x+1;
    for (int x = 0; x < yy.size(); x++)
        mpy[yy[x]] = x+1;
    
    for (auto &x : queries)
    {
        quev[mpx[x.x2+1]].push_back({mpy[x.y1], mpy[x.y2], -1});
        quev[mpx[x.x1]].push_back({mpy[x.y1], mpy[x.y2], 1});
    }
    for (int x = 0; x < pos.size(); x++)
        events[mpx[pos[x].first]].push_back({pos[x].second, x});
    for (int x = 1; x < MAXN; x++)
    {
        for (auto &y : quev[x])
            update(1, MAXN, 1, y.y1, y.y2, y.t);
        for (auto &y : events[x])
        {
            int lx = max(1, mpy[y.first-t]);
            int rx = min(MAXN, mpy[y.first+t]);
            ans[y.second] = max(ans[y.second], query(1, MAXN, 1, lx, rx));
        }
    }
}

int main()
{
    scanf("%i%i%i%i%i", &n, &m, &k, &q, &t);
    vector<pair<int,int>> arr(k);
    for (auto &x : arr)
        scanf("%i%i", &x.first, &x.second);
    vector<que> qu(q);
    for (auto &x : qu)
        scanf("%i%i%i%i", &x.x1, &x.y1, &x.x2, &x.y2);
    test(qu, arr);
    for (auto &x : arr)
        swap(x.first, x.second);
    for (auto &x : qu)
    {
        swap(x.x1, x.y1);
        swap(x.x2, x.y2);
    }
    test(qu, arr);
    long long cnt = 0;
    for (auto &x : ans)
        cnt += x;
    printf("%lli\n", cnt);
}
