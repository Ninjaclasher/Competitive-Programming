#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

vector<vector<int>> adj(MAXN);
vector<int> dp(MAXN);

bool cmp(int a, int b)
{
    return dp[a] > dp[b];
}

int dfs(int u)
{
    if (adj[u].empty())
        return dp[u] = 1;
    for (auto &x : adj[u])
        dfs(x);
    sort(adj[u].begin(), adj[u].end(), cmp);
    for (int x = 0; x < adj[u].size(); x++)
        dp[u] = max(dp[u], dp[adj[u][x]] + x);
    return dp[u];
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> nd(n);
    iota(nd.begin(), nd.end(), 0);
    for (int x = 1; x < n; x++)
    {
        int p;
        scanf("%i", &p);
        adj[p].push_back(x);
    }
    printf("%i\n", dfs(0));
}
