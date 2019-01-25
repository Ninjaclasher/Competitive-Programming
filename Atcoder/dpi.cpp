#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3500;

long double dp[MAXN][MAXN];

int main()
{
    int n;
    scanf("%i", &n);
    long double p;
    dp[0][0] = 1;
    for (int x = 1; x <= n; x++)
    {
        scanf("%Lf", &p);
        for (int y = 0; y <= n; y++)
        {
            dp[x][y] = (1-p) * dp[x-1][y];
            if (y > 0)
                dp[x][y] += p*dp[x-1][y-1];
        }
    }
    long double cnt = 1;
    for (int x = 0; x <= n/2; x++)
        cnt -= dp[n][x];
    printf("%.20Lf\n", cnt);
}
