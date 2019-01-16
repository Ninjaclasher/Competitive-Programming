#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3500;

long long dp[MAXN][MAXN];
long long arr[MAXN];

long long solve(int l, int r)
{
    long long &cur = dp[l][r];
    if (~cur)
        return cur;
    if (l == r)
        return cur = arr[l];
    return cur = max(-solve(l, r-1) + arr[r], -solve(l+1, r) + arr[l]);
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]);
    printf("%lli\n", solve(1, n));
}
