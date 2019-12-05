#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;
const long long MOD = 1000000007;

vector<vector<int>> adj(MAXN);
vector<long long> dp(MAXN);
vector<int> col(MAXN);

long long ans = 0;

long long mod_pow(long long base, long long exp)
{
    long long ret = 1;
    for (base %= MOD; exp; exp >>= 1, base = base*base%MOD)
        if (exp &1)
            ret = ret*base%MOD;
    return ret;
}

long long inv(long long x)
{
    return mod_pow(x, MOD-2);
}

void dfs(int u, int p, int c)
{
    if (adj[u].size() == 1 && u != p)
    {
        dp[u] = (c == col[u]);
        ans += dp[u];
        ans %= MOD;
        return;
    }
    dp[u] = 1;
    for (auto &x : adj[u])
    {
        if (x != p)
        {
            dfs(x, u, c);
            dp[u] *= dp[x] + 1;
            dp[u] %= MOD;
        }
    }
//    long long prev = ans;
    if (col[u] == c)
    {
        ans += dp[u];
        ans %= MOD;
    }
    else
    {
        long long cur = dp[u];
        for (auto &x : adj[u])
        {
            if (x != p)
            {
                cur *= inv(dp[x] + 1);
                cur %= MOD;
                ans += (cur-1) * dp[x] % MOD;
                ans %= MOD;
            }
        }
        dp[u]--;
        dp[u] += MOD;
        dp[u] %= MOD;
    }
//    cout << u << " " << c << " " << ans - prev << endl;
}


int main()
{
    int n, a, b;
    char c;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf(" %c", &c);
        col[x] = (c == 'R');
    }
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s[2] = {-1, -1};
    for (int x = 1; x <= n; x++)
        s[col[x]] = x;
    for (int x = 0; x < 2; x++)
    {
        if (~s[x])
        {
            dfs(s[x], s[x], x);
            fill(dp.begin(), dp.end(), 0);
        }
    }
    printf("%lli\n", ans % MOD);
}

