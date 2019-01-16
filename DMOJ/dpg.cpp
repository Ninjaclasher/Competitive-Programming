#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 100005;
 
vector<vector<int>> adj(MAXN);
vector<int> dp(MAXN, -1);
 
int dfs(int u)
{
    if (~dp[u])
        return dp[u];
    dp[u] = 0;
    for (auto &x : adj[u])
        dp[u] = max(dp[u], dfs(x)+1);
    return dp[u];
}
 
int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
    }
    int ans = 0;
    for (int x = 1; x <= n; x++)
        ans = max(ans, dfs(x));
    printf("%i\n", ans);
}
