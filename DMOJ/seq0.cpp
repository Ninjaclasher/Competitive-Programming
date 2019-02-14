#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

long long dp[MAXN];

int main()
{
    int n, a;
    scanf("%i", &n);
    for (int x = 2; x <= n+1; x++)
    {
        scanf("%i", &a);
        dp[x] = max(dp[x-2] + a, dp[x-1]);
    }
    printf("%lli\n", dp[n+1]);
}
