#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    scanf("%i", &n);
    vector<long long> arr(n+4), dp(n+4, INT_MAX);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]);
    dp[1] = 0;
    for (int x = 1; x < n; x++)
    {
        dp[x+1] = min(dp[x+1], dp[x] + abs(arr[x]-arr[x+1]));
        dp[x+2] = min(dp[x+2], dp[x] + abs(arr[x]-arr[x+2]));
    }
    printf("%lli\n", dp[n]);
}
