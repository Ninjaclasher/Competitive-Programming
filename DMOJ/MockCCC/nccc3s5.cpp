#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long num=0, lazy=0, cost=0;
    bool reset=false;
    friend node operator+(node a, node b)
    {
        return {a.num+b.num, 0, a.cost+b.cost, false};
    }
    inline void clear()
    {
        num = lazy = cost = 0;
        reset = true;
    }
};

node st[10000000];
int nn = 2097152;

inline void lazy(int l, int r, int i)
{
    if (!st[i].reset && !st[i].lazy)
        return;
    if (st[i].reset)
    {
        st[i<<1].num = st[i<<1].cost = st[i<<1].lazy = st[i<<1|1].num = st[i<<1|1].cost = st[i<<1|1].lazy = 0;
        st[i<<1].reset = st[i<<1|1].reset = true;
    }
    if (st[i].lazy)
    {
        int m = l+r>>1;
        st[i<<1].num += st[i].lazy * (m-l+1);
        st[i<<1].cost += st[i].lazy * (m-l+1) * (m+l)/2;
        st[i<<1].lazy += st[i].lazy;
        ++m;
        st[i<<1|1].num += st[i].lazy * (r-m+1);
        st[i<<1|1].cost += st[i].lazy * (r-m+1) * (r+m)/2;
        st[i<<1|1].lazy += st[i].lazy;
    }
    st[i].lazy = st[i].reset = 0;
}

void update(int l, int r, int i, int li, int ri, long long v)
{
    if (l > ri || r < li)
        return;
    if (l ^ r)
        lazy(l, r, i);
    if (l >= li && r <= ri)
    {
        st[i].cost += (r-l+1)*(long long)(l+r)/2*v, st[i].num += (r-l+1)*v;
        st[i].lazy += v;
        return;
    }
    int m = l+r>>1;
    update(l, m, i<<1, li, ri, v), update(m+1, r, i<<1|1, li, ri, v);
    st[i] = st[i<<1] + st[i<<1|1];
}


long long queryA(int l, int r, int i, long long b)
{
    if (l ^ r)
        lazy(l, r, i);
    if (l == r)
    {
        long long maxn = min(b/l,st[i].num);
        st[i].num -= maxn, st[i].cost -= maxn*l;
        return maxn;
    }
    int m = l+r>>1;
    long long tmp;
    if (st[i<<1].cost >= b)
        tmp = queryA(l, m, i<<1, b);
    else
    {
        tmp = st[i<<1].num + queryA(m+1, r, i<<1|1, b-st[i<<1].cost);
        st[i<<1].clear();
    }
    st[i] = st[i<<1] + st[i<<1|1];
    return tmp;
}

long long queryB(int l, int r, int i, long long c, int d)
{
    if (l ^ r)
        lazy(l, r, i);
    if (l == r)
    {
        long long maxn = min(c, st[i].num);
        st[i].num -= maxn, st[i].cost -= maxn*l;
        return maxn*l;
    }
    int m = l+r>>1;
    int ii[] = {l, l+r>>1, r};
    long long tmp;
    if (st[i<<1|d].num >= c)
        tmp = queryB(ii[d]+d, ii[d+1], i<<1|d, c, d);
    else
    {
        tmp = st[i<<1|d].cost + queryB(ii[!d]+(!d), ii[(!d)+1], i<<1|(!d), c-st[i<<1|d].num, d);
        st[i<<1|d].clear();
    }
    st[i] = st[i<<1] + st[i<<1|1];
    return tmp;
}

long long queryC(int l, int r, int i, long long x)
{
    if (l == r)
        return l;
    lazy(l, r, i);
    int m = l+r>>1;
    if (x <= st[i<<1].num)
        return queryC(l, m, i<<1, x);
    else
        return queryC(m+1, r, i<<1|1, x-st[i<<1].num);
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long q, a, b;
    string op;
    cin>>n;
    while(n--)
    {
        cin>>op;
        if (op == "ADD")
        {
            cin>>a>>b;
            update(1, nn, 1, b, b, a);
        }
        else if (op == "ADDRANGE")
        {
            cin>>a>>b;
            update(1, nn, 1, a, b, 1);
        }
        else if (op == "BUYAMT")
        {
            cin>>q;
            printf("%lli\n", queryA(1, nn, 1, q));
        }
        else if (op == "BUYLOW")
        {
            cin>>q;
            printf("%lli\n", queryB(1, nn, 1, q, 0));
        }
        else if (op == "BUYHIGH")
        {
            cin>>q;
            printf("%lli\n", queryB(1, nn, 1, q, 1));
        }
        else if (op == "COST")
        {
            cin>>q;
            if (st[1].num < q)
                printf("-1\n");
            else
                printf("%lli\n", queryC(1, nn, 1, q));
        }
        else if (op == "NUMCONES")
            printf("%lli\n", st[1].num);
        else if (op == "TOTALCOST")
            printf("%lli\n", st[1].cost);
    }
}
