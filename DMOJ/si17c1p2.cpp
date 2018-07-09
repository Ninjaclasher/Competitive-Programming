#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    long long mm = 0;
    scanf("%i%i", &n, &k);
    vector<long long> dp(n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &dp[x]);
        if (x > k)
            dp[x] += dp[x-k-1];
        for (int y = max(x-k, 0); y < x; y++)
            dp[x] = max(dp[x], dp[y]);
        mm = max(mm, dp[x]);
    }
    printf("%lli", mm);
}
