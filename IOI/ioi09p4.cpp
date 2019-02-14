#include <bits/stdc++.h>

using namespace std;

const int MAXN = 51;

int dp[MAXN][MAXN][MAXN][MAXN];
int psa[MAXN][MAXN];

int query(int lx, int ly, int rx, int ry)
{
    return psa[rx][ry] - psa[lx-1][ry] - psa[rx][ly-1] + psa[lx-1][ly-1];
}

int solve(int lx, int ly, int rx, int ry)
{
    int &cur = dp[lx][ly][rx][ry];
    if (~cur)
        return cur;
    if (lx == rx && ly == ry)
        return cur = 0;
    cur = INT_MAX;
    for (int x = lx; x < rx; x++)
        cur = min(cur, solve(lx, ly, x, ry) + solve(x+1, ly, rx, ry));
    for (int y = ly; y < ry; y++)
        cur = min(cur, solve(lx, ly, rx, y) + solve(lx, y+1, rx, ry));
    cur += query(lx, ly, rx, ry);
    return cur;
}

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            scanf("%i", &psa[x][y]);
            psa[x][y] += psa[x-1][y] + psa[x][y-1] - psa[x-1][y-1];
        }
    }
    memset(dp, -1, sizeof dp);
    printf("%i\n", solve(1, 1, n, m));
}
