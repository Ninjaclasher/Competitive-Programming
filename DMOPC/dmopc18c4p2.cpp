#include <bits/stdc++.h>

using namespace std;

const int MAXN = 705*705;

bool dp[2][MAXN];

int main()
{
    int n, a, sum = 0;
    scanf("%i", &n);
    dp[0][0] = true;
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        sum += a;
        for (int y = 0; y <= sum; y++)
            dp[x&1][y] = false;
        for (int y = 0; y <= sum; y++)
        {
            if (dp[x&1^1][y])
            {
                if (y+a <= sum)
                    dp[x&1][y+a] = true;
                dp[x&1][y] = true;
            }
        }
    }
    int mi = INT_MAX;
    for (int x = 0; x <= sum; x++)
        if (dp[n&1][x])
            mi = min(mi, abs(x - (sum-x)));
    printf("%i\n", mi);
}
