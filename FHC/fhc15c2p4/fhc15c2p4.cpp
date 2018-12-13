#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000;

struct node
{
    long long sum, lazymod, lazyinc, lazyincmod;
    int cntOdd[2];
    int cnt[2];
};

const int MAXN = 1000005;
const int MAXM = 1000005;

node st[MAXN<<4];
long long s[MAXN];
long long o[MAXM];
long long a[MAXM];
long long b[MAXM];
long long c[MAXM];
long long d[MAXM];
long long xs, ys, zs, xo, yo, zo, xa, ya, za, xb, yb, zb, xc, yc, zc, xd, yd, zd;

static inline __attribute__((always_inline)) __attribute__((const)) long long sum(long long len, long long v)
{
    return len*(len+1)/2%MOD * v %MOD;
}

static inline void pushup(int l, int r, int v)
{
    int fl = ((l+r>>1)-l+1)&1;
    st[v].sum = (st[v<<1].sum + st[v<<1|1].sum)%MOD;
    st[v].cntOdd[0] = st[v<<1].cntOdd[0] + st[v<<1|1].cntOdd[0^fl];
    st[v].cntOdd[1] = st[v<<1].cntOdd[1] + st[v<<1|1].cntOdd[1^fl];
    st[v].cnt[0] = st[v<<1].cnt[0] + st[v<<1|1].cnt[0^fl];
    st[v].cnt[1] = st[v<<1].cnt[1] + st[v<<1|1].cnt[1^fl];
}

static inline void pushdown(int l, int r, int v)
{
    int len = r-l+1;
    if (~st[v].lazymod)
    {
        st[v].sum = len*st[v].lazymod%MOD;
        if (st[v].lazymod&1)
        {
            st[v].cntOdd[0] = st[v].cnt[0];
            st[v].cntOdd[1] = st[v].cnt[1];
        }
        else
            st[v].cntOdd[0] = st[v].cntOdd[1] = 0;
        if (l ^ r)
        {
            st[v<<1].lazymod = st[v<<1|1].lazymod = st[v].lazymod;
            st[v<<1].lazyinc = st[v<<1|1].lazyinc = 0;
            st[v<<1].lazyincmod = st[v<<1|1].lazyincmod = 0;
        }
        st[v].lazymod = -1;
    }
    if (st[v].lazyincmod)
    {
        st[v].sum += len*st[v].lazyincmod;
        st[v].sum %= MOD;
        if (st[v].lazyincmod&1)
        {
            st[v].cntOdd[0] = st[v].cnt[0]-st[v].cntOdd[0];
            st[v].cntOdd[1] = st[v].cnt[1]-st[v].cntOdd[1];
        }
        if (l ^ r)
        {
            st[v<<1].lazyincmod += st[v].lazyincmod;
            st[v<<1|1].lazyincmod += st[v].lazyincmod;
        }
        st[v].lazyincmod = 0;
    }
    if (st[v].lazyinc)
    {
        st[v].sum += sum(len-1, st[v].lazyinc);
        st[v].sum %= MOD;
        if (st[v].lazyinc&1)
            st[v].cntOdd[1] = st[v].cnt[1] - st[v].cntOdd[1];
        if (l ^ r)
        {
            st[v<<1].lazyinc += st[v].lazyinc;
            st[v<<1|1].lazyinc += st[v].lazyinc;
            st[v<<1|1].lazyincmod += ((l+r>>1)-l+1) * st[v].lazyinc % MOD;
        }
        st[v].lazyinc = 0;
    }
}

void build(int l, int r, int v)
{
    st[v].lazymod = -1;
    if (l == r)
    {
        st[v].sum = s[l];
        if (s[l]&1)
            st[v].cntOdd[0] = 1;
        st[v].cnt[0] = 1;
        return;
    }
    int m = l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    pushup(l, r, v);
}

int queryOdd(int l, int r, int v, int li, int ri)
{
    if (l > ri || r < li)
        return 0;
    pushdown(l, r, v);
    if /*(*/(l >= li && r <= ri)/* || !(st[v].cntOdd[0] || st[v].cntOdd[1]))*/
        return st[v].cntOdd[0] + st[v].cntOdd[1];
    int m = l+r>>1;
    int ans = queryOdd(l, m, v<<1, li, ri) + queryOdd(m+1, r, v<<1|1, li, ri);
//    pushup(l, r, v); CHANGE PUSHDOWN
    return ans;
}

long long querySum(int l, int r, int v, int li, int ri)
{
    if (l > ri || r < li)
        return 0;
    pushdown(l, r, v);
    if (l >= li && r <= ri)
        return st[v].sum;
    int m = l+r>>1;
    long long ans = querySum(l, m, v<<1, li, ri) + querySum(m+1, r, v<<1|1, li, ri);
    //pushup(l, r, v); CHANGE PUSHDOWn
    return ans%MOD;
}

long long updateSum(int l, int r, int v, int li, int ri, long long cc)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
    {
        long long ans = st[v].sum;
        st[v].lazymod = cc;
        pushdown(l, r, v);
        return ans;
    }
    int m = l+r>>1;
    long long ans = updateSum(l, m, v<<1, li, ri, cc) + updateSum(m+1, r, v<<1|1, li, ri, cc);
    pushup(l, r, v);
    return ans%MOD;
}

void updateRange(int l, int r, int v, int li, int ri, long long cc, long long dd)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return;
    if (l >= li && r <= ri)
    {
        st[v].lazyincmod = cc;
        st[v].lazyinc = dd;
        pushdown(l, r, v);
        return;
    }
    int m = l+r>>1;
    updateRange(l, m, v<<1, li, ri, cc, dd);
    updateRange(m+1, r, v<<1|1, li, ri, (cc + max(0, m-max(l, li)+1)*dd)%MOD, dd);
    pushup(l, r, v);
}

void check(int l, int r, int v)
{
    pushdown(l, r, v);
    if (l == r)
    {
        cout<<st[v].sum<<" ";
        return;
    }
    int m = l+r>>1;
    check(l, m, v<<1);
    check(m+1, r, v<<1|1);
//    cout<<l<<" "<<r<<" "<<st[v].sum<<" "<< (st[v<<1].sum + st[v<<1|1].sum)%MOD<<endl;
    assert(st[v].sum%MOD == (st[v<<1].sum + st[v<<1|1].sum)%MOD);
}

int main()
{
    int t;
    scanf("%i", &t);
    for (int i = 1; i <= t; i++)
    {
        memset(st, 0, sizeof st);
        int n, m;
        scanf("%i%i", &n, &m);
        scanf("%lli%lli%lli%lli%lli", &s[1], &s[2], &xs, &ys, &zs);
        scanf("%lli%lli%lli%lli%lli", &o[1], &o[2], &xo, &yo, &zo);
        scanf("%lli%lli%lli%lli%lli", &a[1], &a[2], &xa, &ya, &za);
        scanf("%lli%lli%lli%lli%lli", &b[1], &b[2], &xb, &yb, &zb);
        scanf("%lli%lli%lli%lli%lli", &c[1], &c[2], &xc, &yc, &zc);
        scanf("%lli%lli%lli%lli%lli", &d[1], &d[2], &xd, &yd, &zd);
        for (int x = 3; x <= n; x++)
            s[x] = (xs * s[x-2] + ys * s[x-1] + zs)%MOD;
        for (int x = 3; x <= m; x++)
        {
            o[x] = (xo * o[x-2] + yo * o[x-1] + zo)%4 + 1;
            a[x] = (xa * a[x-2] + ya * a[x-1] + za)%n + 1;
            b[x] = (xb * b[x-2] + yb * b[x-1] + zb)%n + 1;
            c[x] = (xc * c[x-2] + yc * c[x-1] + zc)%MOD;
            d[x] = (xd * d[x-2] + yd * d[x-1] + zd)%MOD;
        }
        //for (int x = 1; x <= n; x++)
        //    cout<<s[x]<<" ";
        //cout<<endl;
        build(1, n, 1);
        long long ans = 0;
        for (int x = 1; x <= m; x++)
        {
//            check(1, n, 1);cout<<endl;
//            cout<<o[x]<<" "<<a[x]<<" "<<b[x]<<" "<<c[x]<<" "<<d[x]<<endl;
            int l = a[x];
            int r = a[x]+b[x]-1;
            if (r > n)
                r %= n;
            long long curAns = 0;
            switch(o[x])
            {
                case 1:
                    curAns += sum(b[x]-1, d[x]) + c[x]*b[x];
                    if (r < l)
                    {
                        updateRange(1, n, 1, l, n, c[x], d[x]);
                        updateRange(1, n, 1, 1, r, (c[x] + (n-l+1)*d[x])%MOD, d[x]);
                    }
                    else
                        updateRange(1, n, 1, l, r, c[x], d[x]);
                break;
                case 2:
                    curAns += c[x]*b[x]%MOD;
                    if (r < l)
                        curAns += updateSum(1, n, 1, l, n, c[x]) + updateSum(1, n, 1, 1, r, c[x]);
                    else
                        curAns += updateSum(1, n, 1, l, r, c[x]);
                break;
                case 3:
                    if (r < l)
                        curAns += querySum(1, n, 1, l, n) + querySum(1, n, 1, 1, r);
                    else
                        curAns += querySum(1, n, 1, l, r);
                break;
                case 4:
                    if (r < l)
                        curAns += queryOdd(1, n, 1, l, n) + queryOdd(1, n, 1, 1, r);
                    else
                        curAns += queryOdd(1, n, 1, l, r);
                break;
            }
            //cout<<curAns<<endl;
            ans = (ans+curAns)%MOD;
            //cout<<ans<<endl;
        }
        printf("Case #%i: %lli\n", i, ans%MOD);
    }
}
