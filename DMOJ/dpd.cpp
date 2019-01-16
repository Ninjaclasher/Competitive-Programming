#include <bits/stdc++.h>

using namespace std;

long long dp[2][100005];

int main()
{
    int n, w, a, b;
    scanf("%i%i", &n, &w);
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        for (int y = 0; y <= w; y++)
        {
            dp[x&1][y] = dp[x&1^1][y];
            if (y-a >= 0)
                dp[x&1][y] = max(dp[x&1][y], dp[x&1^1][y-a] + b);
        }
    }
    long long ma = 0;
    for (int x = 0; x <= w; x++)
        ma = max(ma, dp[n&1^1][x]);
    printf("%lli\n", ma);
}
