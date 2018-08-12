#include <bits/stdc++.h>

using namespace std;

long long dp[2][10005];

const int MOD = 1000000007;

int main()
{
    int n, c;
    scanf("%i%i", &n, &c);
    for (int x = 0; x <= c+1; x++)
        dp[1][x] = 1;
    for (int x = 2; x <= n; x++)
    {
        dp[x&1][0] = 1;
        for (int y = 1; y <= c; y++)
            dp[x&1][y] = (((dp[x&1^1][y] - (y-x >= 0 ? dp[x&1^1][y-x] : 0))%MOD+MOD + dp[x&1][y-1])%MOD+MOD)%MOD;
    }
    printf("%lli\n", (dp[n&1][c]-dp[n&1][c-1]+MOD)%MOD);
}

