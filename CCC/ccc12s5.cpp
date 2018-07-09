#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int r, c, k, a, b;
    scanf("%i%i", &r, &c);
    vector<vector<bool>> aa(r+1, vector<bool>(c+1));
    vector<vector<int>> dp(r+1, vector<int> (c+1));
    scanf("%i", &k);
    while (k--)
    {
        scanf("%i%i", &a, &b);
        aa[a][b] = true;
    }
    dp[1][1] = 1;
    for (int x = 1; x <= r; x++)
        for (int y = 1; y <= c; y++)
            if (!aa[x][y])
                dp[x][y] += dp[x-1][y] + dp[x][y-1];
    printf("%i", dp[r][c]);
    return 0;
}
