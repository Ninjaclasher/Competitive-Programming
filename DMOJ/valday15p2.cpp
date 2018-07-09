#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int c, m, a, b;
    scanf("%i%i", &c, &m);
    vector<vector<int>> dp (c+1, vector<int> (m+1, 0));
    for (int x = 1; x <= c; x++)
    {
        scanf("%i%i", &a, &b);
        for (int y = 1; y <= m; y++)
            dp[x][y] = max (dp[x-1][y], b <= y ? a + dp[x-1][y-b] : 0);
    }
    printf("%d", dp[c][m]);
    return 0;
}
