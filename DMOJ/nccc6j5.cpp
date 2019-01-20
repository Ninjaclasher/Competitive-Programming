#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;

const int MAXN = 1005;

long long dp[MAXN][MAXN], arr[MAXN];

int main()
{
    int n, k, a;
    scanf("%i%i", &n, &k);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        arr[a]++;
    }
    for (int x = 0; x <= n; x++)
        dp[0][x] = 1;
    for (int x = 1; x <= k; x++)
        for (int y = x; y <= n; y++)
            dp[x][y] = (dp[x][y-1] + arr[y] * dp[x-1][y-1])%MOD;
    printf("%lli\n", dp[k][n] % MOD);
}
