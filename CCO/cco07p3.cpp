#include <bits/stdc++.h>

using namespace std;

int dp[10010][510], psa[10010];
int w;

int solve(int n, int k)
{
    if (n <= 0 || k <= 0)
        return 0;
    auto &cur = dp[n][k];
    if (~cur)
        return cur;
    cur = max(solve(n-w, k-1) + psa[n]-(n-w < 0 ? 0 : psa[n-w]), solve(n-1, k));
    for (int x = 1; k >= 2 && x < w; x++)
        cur = max(cur, solve(n-w-x, k-2) + psa[n]-(n-w-x < 0 ? 0 : psa[n-w-x]));
    return cur;
}

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n, k, a;
        memset(dp, -1, sizeof(dp));
        memset(psa, 0, sizeof(psa));
        scanf("%i%i%i", &n, &k, &w);
        for (int x = 1; x <= n; x++)
        {
            scanf("%i", &a);
            psa[x] = psa[x-1]+a;
        }
        int cur = solve(n, k);
        for (int x = 1; x < w; x++)
            cur = max(cur, solve(n-x, k-1) + psa[n]-psa[n-x]);
        printf("%i\n", cur);
    }
}
