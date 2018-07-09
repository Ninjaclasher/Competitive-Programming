#include <bits/stdc++.h>

using namespace std;

long long dp[3][100005];

const int MOD = 1000000007;

long long a(int n);
long long b(int n);
long long c(int n);

long long a(int n)
{
    if (n < 1) return 0;
    if (~dp[0][n]) return dp[0][n];
    return dp[0][n] = (a(n-1) + b(n-2) + a(n-5) + c(n-3))%MOD;
}

long long b(int n)
{
    if (n < 1) return 0;
    if (~dp[1][n]) return dp[1][n];
    return dp[1][n] = (a(n-1) + a(n-2) + a(n-3) + c(n-3) + b(n-2) + b(n-4))%MOD;
}

long long c(int n)
{
    if (n < 1) return 0;
    if (~dp[2][n]) return dp[2][n];
    return dp[2][n] = (a(n-1)*2 + a(n-2) + a(n-3) + c(n-3) + b(n-2) + b(n-4))%MOD;
}

long long f(int n)
{
    if (n <= 0)
        return 0;
    else if (~dp[0][n])
        return dp[0][n];
    else
        return dp[0][n] = (f(n-1) + f(n-3))%MOD;
}

int main()
{
    memset((long long *)dp, -1, 2400120);
    dp[0][1] = 1;
    int n, m;
    scanf("%i%i", &n, &m);
    switch(m)
    {
        case 1:
            return 0 * printf("1\n");
        case 2:
            return 0 * printf("%lli\n", f(n));
        case 3:
            return 0 * printf("%lli\n", a(n));
    }
}
