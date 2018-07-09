#include <bits/stdc++.h>

using namespace std;

unordered_map<int, long long> dp;

long long next(int sz)
{
    if (sz == 1) return 1;
    if (dp[sz]) return dp[sz];
    dp[sz] = 0;
    for (int c = sz; c >= 2;)
    {
        int cur = sz/c, ne = sz/(cur+1);
        dp[sz] += (long long)(c-ne)*next(cur);
        c = ne;
    }
    return dp[sz];
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%lli\n", next(n));
}
