#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2500;

int gr[MAXN][MAXN];
int dp[MAXN][MAXN];

bool valid(int x, int y)
{
    return gr[x][y] && gr[x+1][y-1] && gr[x+1][y] && gr[x+1][y+1];
}

int main()
{
    int n;
    char c;
    scanf("%i", &n);
    long long ans = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf(" %c", &c);
            gr[x][y] = (c == '#');
            ans += gr[x][y];
        }
    }
    for (int x = n-1; x >= 1; x--)
    {
        for (int y = 1; y <= n; y++)
        {
            if (valid(x, y))
                dp[x][y] = min(dp[x+1][y-1], dp[x+1][y+1]) + 1;
            ans += dp[x][y];
        }
    }
    printf("%lli\n", ans);
}
