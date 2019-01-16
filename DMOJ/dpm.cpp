#include <bits/stdc++.h>

using namespace std;

long long dp[105][100005];

long long MOD = 1000000007;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    dp[0][0] = 1;
    for (int x = 1; x <= n; x++)
    {
        long long a;
        scanf("%lli", &a);
        for (int y = 0; y <= k; y++)
        {
            dp[x][y] += dp[x-1][y] - (y-a > 0 ? dp[x-1][y-a-1] : 0);
            if (y > 0)
                dp[x][y] += dp[x][y-1];
            dp[x][y] %= MOD;
            dp[x][y] += MOD;
            dp[x][y] %= MOD;
        }
    }
    printf("%lli\n", dp[n][k] % MOD);
}
