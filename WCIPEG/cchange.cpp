#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, n;
    scanf("%i%i", &k, &n);
    vector<int> dp(k+20000, INT_MAX);
    dp[0] = 0;
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    for (int x = 0; x <= k; x++)
        if (dp[x] != INT_MAX)
            for (auto &y : arr)
                dp[x+y] = min(dp[x]+1, dp[x+y]);
    cout<<dp[k]<<endl;
}
