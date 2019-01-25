#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, w;
    scanf("%i%i", &n, &w);
    vector<pair<int,int>> arr(n+1);
    for (int x = 1; x <= n; x++)
        scanf("%i%i", &arr[x].first, &arr[x].second);
    vector<vector<long long>> dp(105, vector<long long>(100005, LONG_MAX));
    dp[0][0] = 0;
    long long ans = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 0; y < 100005; y++)
        {
            if (y >= arr[x].second && dp[x-1][y-arr[x].second] < LONG_MAX)
                dp[x][y] = min(dp[x-1][y-arr[x].second]+arr[x].first, dp[x-1][y]);
            else
                dp[x][y] = dp[x-1][y];
            if (dp[x][y] <= w)
                ans = max(ans, (long long)y);
        }
    }
    printf("%lli\n", ans);
}
