#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int dp[10000000];

int solve(int x)
{
    if (x <= 0)
        return 1;
    if (x >= 10000000)
        return solve(x/a - b) + solve(x/c - d);
    if (dp[x])
        return dp[x];
    return dp[x] = solve(x/a - b) + solve(x/c - d);
}

int main()
{
    int q, x;
    scanf("%i%i%i%i%i", &a, &b, &c, &d, &q);
    for (int x = 1; x < 10000000; x++)
        solve(x);
    while (q--)
    {
        scanf("%i", &x);
        printf("%i\n", solve(x));
    }
}
