#include <bits/stdc++.h>

using namespace std;

bool dp[2][510];

int main()
{
    int n, cur = 0, k, c;
    scanf("%i", &n);
    dp[1][205] = true;
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &k, &c);
        for (int y = 0; y < k; y++, cur ^= 1)
        {
            memset(dp[cur], 0, sizeof(dp[cur]));
            for (int z = 0; z < 510; z++)
            {
                if (z >= c)
                    dp[cur][z] |= dp[cur^1][z-c];
                if (z+c < 510)
                    dp[cur][z] |= dp[cur^1][z+c];
            }
        }
    }
    for (int x = 0; x <= 205; x++)
        if (dp[cur^1][205-x] || dp[cur^1][205+x])
            return 0 * printf("%i", x);
}
