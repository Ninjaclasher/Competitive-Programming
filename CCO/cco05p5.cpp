#include <bits/stdc++.h>

using namespace std;

int dp[20000][2];

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<int,int>> arr(n);
    scanf("%i%i", &arr[0].first, &arr[0].second);
    dp[0][0] = 2*arr[0].second-arr[0].first-1;
    dp[0][1] = arr[0].second-1;
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &arr[x].first, &arr[x].second);
        int d = arr[x].second - arr[x].first;
        dp[x][0] = min(dp[x-1][0] + abs(arr[x-1].first-arr[x].second) + d, dp[x-1][1] + abs(arr[x-1].second-arr[x].second) + d);
        dp[x][1] = min(dp[x-1][0] + abs(arr[x-1].first-arr[x].first) + d, dp[x-1][1] + abs(arr[x-1].second-arr[x].first) + d);
    }
    printf("%i\n", dp[n-1][1] + n-arr[n-1].second + n-1);
}
