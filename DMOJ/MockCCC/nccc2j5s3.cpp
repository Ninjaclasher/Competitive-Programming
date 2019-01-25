#include <bits/stdc++.h>

using namespace std;

int fuckyouxiaowuc1()
{
    return printf("\n");
}

int main()
{
    int n, m;
    char c;
    scanf("%i%i", &n, &m);
    vector<int> mr(100, 100), mb(100, 0);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            scanf(" %c", &c);
            if (c == 'R')
                mr[x] = min(mr[x], y+1);
            else if (c == 'B')
                mb[x] = max(mb[x], y+1);
        }
        if (mr[x] <= mb[x])
            return 0 * printf("0") * fuckyouxiaowuc1();
    }
    vector<vector<long long>> dp(100, vector<long long>(100));
    dp[n][0] = 1;
    for (int x = n-1; x >= 0; x--)
    {
        long long cc = 0;
        for (int y = 0; y < mr[x]; y++)
        {
            cc += dp[x+1][y];
            if (mb[x] <= y)
                dp[x][y] += cc;
        }
    }
    long long cc = 0;
    for (int x = 0; x <= m; x++)
        cc += dp[0][x];
    return 0 * printf("%lli", cc) * fuckyouxiaowuc1();
}
