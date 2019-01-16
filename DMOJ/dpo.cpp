#include <bits/stdc++.h>

using namespace std;

const int MAXN = 22;
const long long MOD = 1000000007;

long long dp[MAXN][1<<MAXN];

vector<vector<int>> adj(MAXN, vector<int>(MAXN));

int n;

long long solve (int i, int msk)
{
    if (i == n)
        return 1;
    long long &cur = dp[i][msk];
    if (~cur)
        return cur;
    cur = 0;
    for (int x = 0; x < n; x++)
        if (adj[i][x] && (msk>>x&1))
            cur = (cur + solve(i+1, msk ^ (1<<x))) % MOD;
    return cur;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            scanf("%i", &adj[x][y]);
    printf("%lli\n", solve(0, (1<<n)-1));
}
