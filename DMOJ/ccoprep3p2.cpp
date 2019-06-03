#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l;
    scanf("%i%i", &n, &l);
    vector<long long> arr(n+1), psa(n+1), dp(n+1, LONG_MAX);
    dp[0] = 0;
    int prev = 0;
    for (int x = 1; x <= n; x++)
    {
        scanf("%lli", &arr[x]);
        psa[x] = psa[x-1] + arr[x];
        for (int y = prev; y < x; y++)
        {
            long long v = x - y - 1 + psa[x] - psa[y];
            v = (v - l) * (v - l) + dp[y];
            if (v < dp[x])
            {
                prev = y;
                dp[x] = v;
            }
        }
    }
    printf("%lli\n", dp[n]);
}
