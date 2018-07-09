#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
vector<long long> fac(1000005, 1), inv(1000005), aa(501);
vector<vector<long long>> dp(501, vector<long long>(501));
int n, k;

static inline long long mul(long long a, long long b)
{
    return a*b%MOD;    
}

static inline long long mpow(long long b, long long e)
{
    long long ret = 1;
    for (b %= MOD; e; e>>=1, b = mul(b,b))
        if (e&1)
            ret = mul(ret, b);
    return ret;
}

static inline long long choose(int n, int k)
{
    return mul(mul(fac[n],inv[k]), inv[n-k]);
}

static inline long long permute(int n, int k)
{
    return (n < k) ? 0 : mul(fac[n],inv[n-k]);
}

int ne(int l, int r, int he)
{
    if (l > r)
        return 0;
    int mi = l;
    for (int x = l; x <= r; x++)
        if (aa[x] < aa[mi]) 
            mi = x;
    int ll = ne(l, mi-1, aa[mi]), rr = ne(mi+1, r, aa[mi]), len = r-l+1;
    vector<long long> dp2(501);
    for (int x = 0; x <= min(len, k); x++)
        for (int y = 0; y <= min(len, k)-x; y++)
            dp2[x+y] = (dp2[x+y] + mul(dp[ll][x],dp[rr][y]))%MOD;
    for (int x = 0; x <= min(len, k); x++)
        for (int y = 0; y <= x; y++)
            dp[mi][x] = (dp[mi][x] + mul(mul(choose(len-x+y, y), permute(aa[mi]-he, y)), dp2[x-y]))%MOD;
    return mi;
}


int main()
{
    dp[0][0] = 1;
    for (int x = 1; x < fac.size(); x++)
        fac[x] = mul(fac[x-1], x);
    inv[1000004] = mpow(fac.back(), MOD-2);
    for (int x = inv.size()-2; x >= 0; x--)
        inv[x] = mul(inv[x+1], x+1);
    scanf("%i%i", &n, &k);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &aa[x]);
    printf("%lli\n", dp[ne(1, n, 0)][k]);
}
