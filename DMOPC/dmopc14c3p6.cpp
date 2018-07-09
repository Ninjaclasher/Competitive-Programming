#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int n, t, ma = 0;
    vector<pair<int,int>> ps(3);
    scanf("%i%i", &n, &t);
    vector<vector<int>> dp(2, vector<int>(t+1));
    for (int x = 0; x < n; x++)
    {
        for (auto &y : ps)
            scanf("%i%i", &y.first, &y.second);
        for (int y = 1; y <= t; y++)
        {
            dp[1][y] = dp[0][y];
            for (auto &z : ps)
                if (z.first <= y)
                    dp[1][y] = max(dp[1][y], z.second + dp[0][y-z.first]);
        }
        swap(dp[0], dp[1]);
        fill(dp[1].begin(), dp[1].end(), 0);
    }
    for (int x = 0; x <= t; x++)
        ma = max(ma, dp[0][x]);
    printf("%i", ma);
    return 0;
}
