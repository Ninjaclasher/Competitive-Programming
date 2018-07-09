#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b, ma = -1, mg = -1;
    scanf("%i%i", &n, &m);
    vector<vector<int>> dp(2, vector<int> (10000));
    dp[0][m] = 1;
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        for (int y = 0; y < 10000; y++)
        {
            dp[1][y] = max(dp[0][y], dp[1][y]);
            if (dp[0][y] && y - a >= 0)
                dp[1][y-a+b] = max(dp[1][y-a+b], dp[0][y]+1);
        }
        for (int y = 0; y < 10000; y++)
        {
            if (dp[1][y] > ma)
                ma = dp[1][y], mg = y;
            else if (dp[1][y] == ma)
                mg = max(mg, y);
        }
        swap(dp[0], dp[1]);
        fill(dp[1].begin(), dp[1].end(), 0);
    }
    printf("%i %i", ma-1, mg);
}
