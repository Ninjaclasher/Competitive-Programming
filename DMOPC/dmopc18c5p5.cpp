/*
 * CHEESE SOLUTION
 * SHOULD NOT PASS
 * USE AT YOUR OWN RISK
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> a(MAXN), b(MAXN);
vector<long long> d(MAXN), dd(MAXN), dp(MAXN, LLONG_MAX);

int main()
{   
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        scanf("%i%i", &a[x], &b[x]);
    for (int x = 1; x <= n; x++)
    {
        d[x] = abs(a[x]-b[x]);
        dd[x] = abs(a[x+1]-b[x]) + dd[x-1];
    }
    dp[0] = 0;
    set<pair<long long,int>> gg;
    gg.insert({0, 0});
    for (int x = 1; x <= n; x++)
    {
        for (auto &y : gg)
        {
            long long cur = y.first;
            if (cur >= dp[x])
                break;
            dp[x] = min(dp[x], cur + abs(a[y.second+1]-b[x]));
        }
        dp[x] += dd[x-1];
        if (x < n)
            dp[x] -= dd[x];
        gg.insert({dp[x], x});
    }
    printf("%lli\n", dp[n]);
}
