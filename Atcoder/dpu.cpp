#include <bits/stdc++.h>

using namespace std;

const int MAXN = 17;

int arr[MAXN][MAXN];
long long dp[1<<MAXN], pre[1<<MAXN];
int n;

long long solve(int msk)
{
    if (msk == 0)
        return 0;
    if (~dp[msk])
        return dp[msk];
    dp[msk] = 0;
    for (int x = msk; x > 0; x = (x - 1) & msk)
        dp[msk] = max(dp[msk], pre[x] + solve(msk ^ x));
    return dp[msk];
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            scanf("%i", &arr[x][y]);
    for (int x = 0; x < (1<<n); x++)
        for (int y = 0; y < n; y++)
            if (x>>y&1)
                for (int z = 0; z < y; z++)
                    if (x>>z&1)
                        pre[x] += arr[y][z];
    printf("%lli\n", solve((1<<n) - 1));
}
