#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;
const int LOGN = 10;
const int SQRN = 50;
const int MOD = 1000000007;

long long mod_pow(long long base, long long exp)
{
    long long ret = 1;
    for (; exp; exp >>= 1, base = base*base%MOD)
        if (exp &1)
            ret = ret*base%MOD;
    return ret;
}

long long inv(long long v)
{
    return mod_pow(v, MOD-2);
}

vector<vector<int>> adj(MAXN);
// how many trees have a height of h with root at u?
long long height_counts[2][LOGN][MAXN];

// TODO: optimize
long long dp[MAXN];
long long pre_dp[SQRN][LOGN][4 * MAXN];
long long suf_dp[SQRN][LOGN][4 * MAXN];

int n, SQ;
long long ans = 0;
int _t = 0;

void precompute(int u, int p, int k)
{
    for (auto &x : adj[u])
        if (x != p)
            precompute(x, u, k);
    for (int _d = 1; _d < LOGN; _d++)
    {
        for (int _k = 1; _k <= k; _k++)
            dp[_k] = 0;
        for (auto &x : adj[u])
            if (x != p)
                for (int _k = k; _k >= 1; _k--)
                    dp[_k] = (dp[_k] + dp[_k-1] * height_counts[1][_d-1][x]) % MOD;
        height_counts[0][_d][u] = dp[k-1];
        height_counts[1][_d][u] = dp[k];
    }
}

void solve(int u, int p, int k)
{
    long long u_heights[LOGN], x_heights[LOGN];
    u_heights[0] = 1;
    for (int _d = 1; _d < LOGN; _d++)
    {
        u_heights[_d] = height_counts[1][_d][u];
        ans += height_counts[1][_d][u];
    }
    int st = _t;
    int en = st + adj[u].size() + 1;
    _t = en + 1;

    for (int _d = 1; _d < LOGN; _d++)
    {
        int _i = st+1;
        for (int s = st; s <= en; s++)
            suf_dp[0][_d][s] = pre_dp[0][_d][s] = 1;
        for (auto &x : adj[u])
        {
            for (int _k = 1; _k <= k; _k++)
                pre_dp[_k][_d][_i] = (pre_dp[_k][_d][_i-1] + pre_dp[_k-1][_d][_i-1] * height_counts[1][_d-1][x]) % MOD;
            _i++;
        }
        _i = en-1;
        for (int e = (int)adj[u].size()-1; e >= 0; e--)
        {
            auto &x = adj[u][e];
            for (int _k = 1; _k <= k; _k++)
                suf_dp[_k][_d][_i] = (suf_dp[_k][_d][_i+1] + suf_dp[_k-1][_d][_i+1] * height_counts[1][_d-1][x]) % MOD;
            _i--;
        }
    }
    int _i = st+1;
    for (auto &x : adj[u])
    {
        if (x != p)
        {
            for (int _d = 1; _d < LOGN; _d++)
            {
                long long cnt = 0;
                for (int _k = 0; _k <= k; _k++)
                    cnt = (cnt + pre_dp[_k][_d][_i-1] * suf_dp[k-_k][_d][_i+1]) % MOD;
                height_counts[1][_d][u] = cnt;
                x_heights[_d] = height_counts[1][_d][x];
                height_counts[1][_d][x] = (height_counts[1][_d][x] + height_counts[0][_d][x] * height_counts[1][_d-1][u]) % MOD;
            }
            solve(x, u, k);
            for (int _d = 1; _d < LOGN; _d++)
                height_counts[1][_d][x] = x_heights[_d];
        }
        _i++;
    }

    for (int _d = 1; _d < LOGN; _d++)
        height_counts[1][_d][u] = u_heights[_d];
}

int main()
{
    dp[0] = 1;
    for (int x = 0; x < MAXN; x++)
        height_counts[0][0][x] = height_counts[1][0][x] = 1;
    scanf("%i", &n);
    SQ = (int)sqrt(n);
    for (int x = 1; x < n; x++)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int k = 2; k <= SQ; k++)
    {
        _t = 0;
        precompute(1, 1, k);
        solve(1, 1, k);
    }
    for (int x = 1; x <= n; x++)
    {
        long long _n = adj[x].size();
        if (_n <= SQ)
            continue;
        long long cur = 1;
        for (int k = 1; k <= _n; k++)
        {
            cur = (cur * (_n - k + 1) % MOD) * inv(k) % MOD;
            if (k > SQ)
                ans = (ans + cur) % MOD;
        }
    }
    printf("%lli\n", (ans + n) % MOD);
}
