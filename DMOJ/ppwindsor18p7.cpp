#include <bits/stdc++.h>

using namespace std;

long long dp[1005];

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> v(n+1);
    for (int x = 1; x <= n; x++)
        scanf("%i", &v[x]);
    for (int x = 1; x <= n; x++)
    {
        dp[x] = dp[x-1];
        for (int y = 1; y <= x; y++)
        {
            dp[x] = max(dp[x-y]+v[y], dp[x]);
        }
    }
    printf("%lli\n", dp[n]);
}
