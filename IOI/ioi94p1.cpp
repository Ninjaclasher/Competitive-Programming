#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ma = 0;
    scanf("%i", &n);
    int dp[n+1][n+1], arr[n+1][n+1];
    for (int x = 1; x <= n; x++)
        for (int y = 0; y < x; y++)
            scanf("%i", &arr[x][y]), dp[x][y] = arr[x][y];
    for (int x = 1; x < n; x++)
    {
        for (int y = 0; y < x; y++)
        {
            dp[x+1][y+1] = max(dp[x+1][y+1], dp[x][y]+arr[x+1][y+1]);
            dp[x+1][y] = max(dp[x+1][y], dp[x][y]+arr[x+1][y]);
        }
    }
    for (int x = 0; x < n; x++)
        ma = max(ma, dp[n][x]);
    printf("%i", ma);
}
