#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXS = 1005;
 
int dp[MAXS][MAXS];
 
int main()
{
    int h, w;
    scanf("%i%i", &h, &w);
    vector<vector<char>> arr(h, vector<char>(w));
    dp[0][0] = 1;
    for (int x = 0; x < h; x++)
    {
        for (int y = 0; y < w; y++)
        {
            scanf(" %c", &arr[x][y]);
            if (arr[x][y] == '#')
                continue;
            if (x > 0)
                dp[x][y] += dp[x-1][y];
            if (y > 0)
                dp[x][y] += dp[x][y-1];
            dp[x][y] %= 1000000007;
        }
    }
    printf("%i\n", dp[h-1][w-1]);
}
