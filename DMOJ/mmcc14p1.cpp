#include <bits/stdc++.h>

using namespace std;

int dp[1<<12][20], m[20];

int n, s;

int main()
{
    memset(dp, 0, sizeof(dp));
    scanf("%i%i", &n, &s);
    for (int x = 0; x < n; x++)
        scanf("%i", &m[x]);
    for (int x = 0; x < n; x++)
        for (int y = 0; y <= s; y++)
            dp[1<<x][y] = (m[x]+y)*(m[x]+y) + y;
    for (int x = 1; x < (1<<n); x++)
        for (int y = 1; y < (1<<n); y++)
            if (!(x&y))
                for (int c = 0; c < n; c++)
                    if (!((x|y)>>c&1))
                        for (int i = 0; i <= s; i++)
                            for (int j = 0; j <= s; j++)
                                for (int k = s-i-j; k >= 0; k--)
                                        dp[x|y|(1<<c)][i+j+k] = max(dp[x|y|(1<<c)][i+j+k], min(dp[x][i]*dp[y][j], (m[c]+k)*(m[c]+k)) + k);
    printf("%i\n", dp[(1<<n)-1][s]);
}
