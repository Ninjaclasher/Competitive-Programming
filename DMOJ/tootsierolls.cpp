#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

vector<vector<int>> adj(MAXN);
vector<vector<int>> pos(MAXN);
vector<int> st(MAXN), en(MAXN), val(MAXN);
int cc = 0;

long long dp[MAXN][MAXN], psa[MAXN];

void dfs(int u, int p)
{
    st[u] = ++cc;
    psa[st[u]] = val[u];
    for (auto &x : adj[u])
        if (x != p)
            dfs(x, u);
    en[u] = cc;
}

int main()
{
    int n, k, a, b;
    scanf("%i%i", &n, &k);
    for (int x = 1; x <= n; x++)
        scanf("%i", &val[x]);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    for (int x = 1; x <= n; x++)
        psa[x] += psa[x-1];
    for (int x = 1; x <= n; x++)
        pos[en[x]].push_back(st[x]);
    for (int x = 1; x <= n; x++)
    {
        dp[x][0] = dp[x-1][0];
        for (int y = 1; y <= k; y++)
        {
            dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
            for (auto &z : pos[x])
                dp[x][y] = max(dp[x][y], dp[z-1][y-1] + psa[x] - psa[z-1]);
        }
    }
    printf("%lli\n", dp[n][k]);
}
