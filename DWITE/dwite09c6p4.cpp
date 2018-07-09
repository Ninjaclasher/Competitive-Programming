#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int ii = 0; ii < 5; ii++)
    {
        int n, m;
        scanf("%i%i", &m, &n);
        vector<int> cc(n);
        for (auto &x : cc)
            scanf("%i", &x);
        vector<int> dp(1000, INT_MAX);
        dp[0] = 0;
        for (int x = 0; x <= m; x++)
            if (dp[x] != INT_MAX)
                for (auto &y : cc)
                    dp[x+y] = min(dp[x+y], dp[x]+1);
        printf("%i\n", dp[m]);
    }
}
