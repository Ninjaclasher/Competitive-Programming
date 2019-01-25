#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<long long> arr(n+200), dp(n+200, INT_MAX);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]);
    dp[1] = 0;
    for (int x = 1; x < n; x++)
        for (int y = 1; y <= k; y++)
            dp[x+y] = min(dp[x+y], dp[x] + abs(arr[x]-arr[x+y]));
    printf("%lli\n", dp[n]);
}
