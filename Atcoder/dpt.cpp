#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3005;
const int MOD = 1000000007;

int dp[MAXN][MAXN];

int main()
{
    int n;
    scanf("%i", &n);
    string s;
    cin>>s;
    dp[0][1] = dp[0][2] = dp[0][3] = 1;
    for (int x = 1; x < n; x++)
    {
        if (s[x-1] == '>')
            for (int y = 1; y <= x+1; y++)
                dp[x][y] = (dp[x-1][x] - dp[x-1][y-1] + MOD) % MOD;
        else
            for (int y = 1; y <= x+1; y++)
                dp[x][y] = dp[x-1][y-1];
        for (int y = 1; y <= x+2; y++)
        {
            dp[x][y] += dp[x][y-1];
            dp[x][y] %= MOD;
        }
    }
    printf("%i\n", dp[n-1][n]);
}
