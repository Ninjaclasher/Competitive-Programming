#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    char c;
    scanf("%i%i", &n, &m);
    int nn = 1<<n;
    vector<int> ww(55);
    vector<long long> dp(2000000, LONG_MAX);
    for (int x = 0; x < n; x++)
    {
        bool a = false;
        for (int y = 0; y < m; y++)
        {
            scanf(" %c", &c);
            if (c == 'X')
                a = true, ww[y] |= 1<<x;
        }
        for (int y = 0; y < m && !a; y++)
            ww[y] |= 1<<x;
    }
    dp[0] = 0;
    for (int x = 0; x < nn; x++)
        for (int y = 0; y < m; y++)
            if (dp[x] != INT_MAX && __builtin_popcountll(dp[x | ww[y]]) > __builtin_popcountll(dp[x])+1)
                dp[x | ww[y]] = dp[x] | (1LL<<y);
    printf("%i\n", __builtin_popcountll(dp[nn-1]));
    vector<int> ans;
    for (int x = 0; x < m; x++)
        if (dp[nn-1]>>x&1)
            ans.push_back(x+1);
    for (int x = 0; x < ans.size(); x++)
        printf("%i%c", ans[x], x == ans.size()-1 ? '\n' : ' ');
}
