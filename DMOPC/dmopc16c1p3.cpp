#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    scanf("%i", &n);
    vector<int> dp(n+1), arr(n+1);
    dp[0] = 0;
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &arr[x]);
        arr[x]*=2;
        dp[x] = dp[x-1] + arr[x];
        if (x > 1)
            dp[x] = min(dp[x],  dp[x-2] - min(arr[x-1], arr[x])/2 + arr[x-1] + arr[x]);
        if (x > 2)
            dp[x] = min(dp[x], dp[x-3] - min(arr[x-2], min(arr[x-1], arr[x])) +arr[x-2] + arr[x-1] + arr[x]);
    }
    printf("%.1f", dp[n]/2.0);
    return 0;
}
