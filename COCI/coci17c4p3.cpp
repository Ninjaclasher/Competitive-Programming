#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

long long mul(long long a, long long b)
{
    return a*b%MOD;
}

int main()
{
    int n, m, k, a, b;
    char t;
    scanf("%i%i%i", &n, &m, &k);
    vector<long long> r(1000005, 1), c(1000005, 1);
    while (k--)
    {
        scanf(" %c%i%i", &t, &a, &b);
        switch(t)
        {
            case 'R':
                r[a] = mul(r[a],b);
            break;
            case 'S':
                c[a] = mul(c[a],b);
            break;
        }
    }
    long long rv = 0, rsum = 0;
    for (int x = 1; x <= n; x++)
        rv = (rv + mul(r[x],(1+mul(x-1,m))))%MOD, rsum = (rsum+r[x])%MOD;
    long long s = 0;
    for (int x = 1; x <= m; x++)
        s = (s+mul(c[x], (rv+mul(x-1,rsum))))%MOD;
    printf("%lli\n", s);
}
