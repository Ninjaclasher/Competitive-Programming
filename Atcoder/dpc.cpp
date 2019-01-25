#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int dp[3][MAXN];

int main()
{
    int n, a, b, c;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        dp[0][x] = max(dp[1][x-1], dp[2][x-1]) + a;
        dp[1][x] = max(dp[0][x-1], dp[2][x-1]) + b;
        dp[2][x] = max(dp[0][x-1], dp[1][x-1]) + c;
    }
    printf("%i\n", max(dp[0][n], max(dp[1][n], dp[2][n])));
}
