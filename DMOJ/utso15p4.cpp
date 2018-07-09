#include <bits/stdc++.h>

using namespace std;

struct ed
{
    int v, l, r;
};

vector<vector<ed>> adj(2010);
vector<vector<long double>> dp(2010, vector<long double>(2010));

int main()
{
    int n, m, t, a, b, c, d;
    scanf("%i%i%i", &n, &m, &t);
    while (m--)
    {
        scanf("%i%i%i%i", &a, &b, &c, &d);
        adj[a].push_back({b, c, d});
    }
    dp[1][0] = 1.0;
    for (int x = 0; x <= t; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if (x > 0 && (y ^ 1 || x ^ 1))
                dp[y][x] += dp[y][x-1];
            if (y == n) continue;
            for (auto &v : adj[y])
            {
                long double choose = dp[y][x]/(v.r-v.l+1)/adj[y].size();
                if (x + v.l > t) continue;
                dp[v.v][x+v.l] += choose, dp[v.v][min(x+v.r+1, t+1)] -= choose;
            }
        }
    }
    long double su = 0, s2 = 0;
    for (int x = 0; x <= t; x++)
        su += dp[n][x], s2 += dp[n][x]*x;
    printf("%.10Lf", s2/su);
}
