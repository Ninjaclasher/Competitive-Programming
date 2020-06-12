#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long dp[2048][1005][2];

string k;
int aa;

long long solve(int msk, int i, int nonZero, int top)
{
    if (i == k.size())
        return (aa&msk) == aa;
    if (top)
    {
        long long ans = 0;
        int cur = k[i] - '0';
        for (int x = 0; x <= cur; x++)
            ans += solve(msk | (nonZero || i == k.size()-1 || x ? (1<<x) : 0), i+1, nonZero || x, x == cur);
        return ans %= MOD;
    }
    if (~dp[msk][i][nonZero])
        return dp[msk][i][nonZero];
    dp[msk][i][nonZero] = 0;
    for (int x = 0; x < 10; x++)
        dp[msk][i][nonZero] += solve(msk | (nonZero || i == k.size()-1 ||  x ? (1<<x) : 0), i+1, nonZero || x, 0);
    return dp[msk][i][nonZero] %= MOD;
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n, a;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        aa |= 1<<a;
    }
    cin>>k;
    printf("%lli\n", solve(0, 0, 0, 1));
}
