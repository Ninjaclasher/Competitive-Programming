#include <bits/stdc++.h>

using namespace std;

long long fastpow(long long b, long long e, long long m)
{
    long long ret = 1;
    for (b %= m; e; e>>=1, b = (b*b)%m)
        if (e&1)
            ret = (ret*b)%m;
    return ret%m;
}

int main()
{
    long long n, m, k, v;
    scanf("%lli%lli%lli%lli", &n, &m, &k, &v);
    assert(1 <= n && n <= 1000000000);
    assert(1 <= m && m <= 2000000000);
    assert(0 <= k && k <= 63);
    assert(0 <= v && v <= (1ULL<<k)-1);
    long long q1 = 1, q2 = 1, q3 = 1;
    long long p1 = fastpow(2, n-1, m), p2 = (fastpow(2, n, m)+m-1)%m;
    for (int x = 0; x < k; x++)
    {
        q1 = (q1*p1)%m;
        if (v>>x&1)
            q2 = (q2*p2)%m;   
        else
            q3 = (q3*p2)%m;
    }
    printf("%lli\n%lli\n%lli\n", q1, q2, q3);
}
