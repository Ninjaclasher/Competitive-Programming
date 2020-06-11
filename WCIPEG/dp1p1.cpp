#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    scanf("%i", &n);
    vector<int> dp(n+1);
    scanf("%i", &dp[0]);
    scanf("%i", &dp[1]);
    dp[1] = max(dp[1], dp[0]);
    for (int x = 2; x < n; x++)
    {
        scanf("%i", &a);
        dp[x] = max(dp[x-2]+a, dp[x-1]);
    }
    cout<<dp[n-1]<<endl;
}
