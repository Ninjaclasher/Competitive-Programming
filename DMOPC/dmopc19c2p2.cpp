#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

long long dp[MAXN][MAXN];

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++)
            scanf("%lli", &dp[x][y]);
    for (int x = 2; x <= m; x++)
        dp[1][x] += dp[1][x-1];
    for (int x = 2; x <= n; x++)
        dp[x][1] += dp[x-1][1];
    for (int x = 2; x <= n; x++)
        for (int y = 2; y <= m; y++)
            dp[x][y] += min(dp[x-1][y], dp[x][y-1]);
    printf("%lli\n", dp[n][m]);
}
