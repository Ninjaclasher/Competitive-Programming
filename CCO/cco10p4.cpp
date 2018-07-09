#include <bits/stdc++.h>

using namespace std;

int dp[6][3010];

int main() 
{
    memset(dp, -1, sizeof(dp));
    int t, n, b, c, v, a;
    scanf("%i%i", &t, &n);
    vector<vector<pair<int,int>>> comp(6);
    while (n--)
    {
        scanf("%i%i%i", &c, &v, &a);
        comp[a].push_back(make_pair(c, v));
    }
    scanf("%i", &b);
    for (auto &x : comp)
        sort(x.begin(), x.end());
    dp[0][0] = 0;
    for (int x = 1; x <= t; x++)
        for (int y = 0; y <= b; y++)
            if (~dp[x-1][y])
                for (auto &z : comp[x])
                    if (y+z.first <= b)
                        dp[x][y+z.first] = max(dp[x][y+z.first], dp[x-1][y]+z.second);
                    else
                        break;
    int ma = -1;
    for (int x = 0; x <= b; x++)
        ma = max(ma, dp[t][x]);
    printf("%i", ma);
    return 0;
}
