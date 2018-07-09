#include <bits/stdc++.h>

using namespace std;

pair<int,int> dp[55][1001];

int main()
{
    vector<int> h(55), e(55), p(55);
    int n, s;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        scanf("%i%i%i", &h[x], &e[x], &p[x]);
    scanf("%i", &s);
    for (int x = 1; x <= n; x++)
        for (int y = 0; y <= s; y++)
            for (int a = y, val = h[x], ss = 0, cnt = 0; a >= 0; ss += val, val -= e[x], a -= p[x], cnt++)
            {
                dp[x][y] = max(dp[x][y], {ss+dp[x-1][a].first, -cnt+dp[x-1][a].second});
                if (val <= 0)
                    break;
            }
    printf("%i\n%i\n", dp[n][s].first, -dp[n][s].second);
}
