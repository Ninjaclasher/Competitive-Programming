#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

vector<pair<long long,long long>> dp(100005, make_pair(-1, -1));
vector<vector<int>> adj(100005);

pair<int,int> dfs(int u)
{
    if (~dp[u].first)
        return dp[u];
    if (adj[u].empty())
        return dp[u] = {0, 1};
    dp[u] = {0,0};
    for (auto &x : adj[u])
    {
        pair<int,int> tmp = dfs(x);
        dp[u].second += tmp.second;
        dp[u].first += tmp.first+tmp.second;
        dp[u].second %= MOD;
        dp[u].first %= MOD;
    }
    return dp[u];
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m) == 2;
    vector<bool> root(100001, true);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        root[b] = false;
        adj[a].push_back(b);
    }
    int sum = 0;
    for (int x = 1; x <= n; x++)
        if (root[x])
            sum += dfs(x).first, sum %= MOD;
    printf("%i", sum);
}
