#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c;
    scanf("%i%i%i%i", &n, &a, &b, &c);
    vector<long long> arr(n+1), psa(n+1), dp(n+1, LONG_MIN);
    dp[0] = 0;
    int prev = 0;
    for (int x = 1; x <= n; x++)
    {
        scanf("%lli", &arr[x]);
        psa[x] += psa[x-1] + arr[x];
        for (int y = prev; y < x; y++)
        {
            long long p = psa[x] - psa[y];
            long long v = a * p * p + b * p + c + dp[y];
            if (v > dp[x])
            {
                prev = y;
                dp[x] = v;
            }
        }
    }
    printf("%lli\n", dp[n]);
}
