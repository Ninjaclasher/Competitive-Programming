#include <bits/stdc++.h>

using namespace std;

struct po
{
    long long a, b;
    friend bool operator<(po a, po b)
    {
        return a.a < b.a;
    }
};

const long long MOD = 998244353;

int n;
long long t;
vector<po> arr;

__int128 maxTake(long long v, po o)
{
    return (o.a-v)/o.b+1;
}

bool possible(long long v)
{
    __int128 cur = 0;
    for (int x = 0; x < n; x++)
    {
        __int128 k = max((__int128)0LL,maxTake(v, arr[x]));
        cur += k;
        if (cur >= t || k >= t)
            return false;
    }
    return true;
}

__int128 happy(__int128 k, po o)
{
    k %= MOD;
    return ((o.a %MOD * k - ((k+MOD-1)%MOD*k/2)%MOD*o.b%MOD)%MOD+MOD)%MOD;
}

long long run(long long v)
{
    __int128 ans = 0, cur = 0;
    priority_queue<po> buf;
    for (int x = 0; x < n; x++)
    {
        __int128 k = max((__int128)0LL,maxTake(v, arr[x]));
        cur += k;
        if (cur > t || k > t)
            return LONG_MIN;
        ans = (ans+happy(k, arr[x]))%MOD;
        buf.push(po{arr[x].a-k*arr[x].b, arr[x].b});
    }
    for (long long x = 0; !buf.empty() && x < t-cur; x++)
    {
        auto u = buf.top();
        if (u.a <= 0)
            break;

        ans = (ans+u.a)%MOD;
        buf.pop();
        u.a -= u.b;
        if (u.a > 0)
            buf.push(u);
    }
    return ans;
}

int main()
{
    scanf("%i%lli", &n, &t);
    arr.resize(n);
    for (auto &x : arr)
        scanf("%lli%lli", &x.a, &x.b);
    long long l = 1, r = 1000000000000000000;
    while (l <= r)
    {
        long long m = l+r>>1;
        if (possible(m))
            r = m-1;
        else
            l = m+1;
    }
    long long ans = run(r+1);
    printf("%lli\n", ans%MOD);
}

