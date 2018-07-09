#include <bits/stdc++.h>

using namespace std;

long long dp[2][502][502];

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    for (int x = 0; x < 502; x++)
        dp[0][0][x] = 1;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            for (int z = 0; z <= k; z++)
            {
                dp[x&1][y][z] = dp[x&1^1][y][z] + (y ? dp[x&1^1][y-1][z] : 0) + dp[x&1^1][y+1][z] - (z-y-1 >= 0 ? dp[x&1^1][y+1][z-y-1] : 0);
                if (z)
                    dp[x&1][y][z] -= dp[x&1^1][y][z-1] + (y ? dp[x&1^1][y-1][z-1] : 0) - dp[x&1][y][z-1];
                dp[x&1][y][z] %= 1000000007;
            }
        }
    }
    printf("%lli", (((dp[n&1][0][k]-dp[n&1][0][k-1])%1000000007)+1000000007)%1000000007);
}
