#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
const int MAXC = 101;

long long dp[MAXN][MAXC], tmp[MAXN][MAXC];

int main()
{
    for (int x = 0; x < MAXN; x++)
        for (int y = 0; y < MAXC; y++)
            dp[x][y] = tmp[x][y] = LONG_MIN;
    dp[0][0] = 0;
    int n, m;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        int xx, yy, b, s;
        scanf("%i%i%i%i", &xx, &yy, &b, &s);
        for (int prev = 0; prev < MAXC; prev++)
        {
            if (dp[x-1][prev] != LONG_MIN)
            {
                for (int sell = 0; sell <= yy && prev - sell >= 0; sell++)
                    tmp[x][prev - sell] = max(tmp[x][prev - sell], dp[x-1][prev] - prev * m + sell * s);
            }
        }
        for (int y = 0; y < MAXC; y++)
        {
            if (tmp[x][y] != LONG_MIN)
            {
                for (int buy = 0; buy <= xx && y + buy < MAXC; buy++)
                    dp[x][y + buy] = max(dp[x][y + buy], tmp[x][y] - buy * b);
            }
        }
    }
    long long ans = 0;
    for (int x = 0; x < MAXC; x++)
        ans = max(ans, dp[n][x]);
    printf("%lli\n", ans);
}
