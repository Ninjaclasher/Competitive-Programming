#include <bits/stdc++.h>

using namespace std;

const int MAXL = 1005;

int dp[MAXL][MAXL];

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<int> a(n+1), b(m+1);
    for (int x = 1; x <= n; x++)
        scanf("%i", &a[x]);
    for (int x = 1; x <= m; x++)
        scanf("%i", &b[x]);
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            if (a[x] == b[y])
                dp[x][y] = dp[x-1][y-1] + 1;
            else
                dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
        }
    }
    printf("%i\n", dp[n][m]);
}
