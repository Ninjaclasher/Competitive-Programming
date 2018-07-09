#include <bits/stdc++.h>

using namespace std;

long long dp[2][2][5005];


struct pp
{
    int g, h, q, t;
};

vector<pp> aa(5005);

int main()
{
    int n, h, cur = 0;
    scanf("%i%i", &n, &h);
    for (int x = 0; x < n; x++)
        scanf("%i%i%i%i", &aa[x].g, &aa[x].h, &aa[x].q, &aa[x].t);
    for (int x = 0; x < n; x++, cur ^= 1)
    {
        for (int y = 0; y <= h; y++)
        {
            dp[cur][0][y] = dp[cur][1][y] = dp[cur^1][0][y];
            if (y >= aa[x].h)
                dp[cur][0][y] = max(dp[cur][0][y], dp[cur][1][y-aa[x].h]+aa[x].g);
            if (y >= aa[x].t)
                dp[cur][1][y] = max(dp[cur][1][y], dp[cur][1][y-aa[x].t]+aa[x].q);
        }
    }

    printf("%lli\n", dp[cur^1][0][h]);
}
