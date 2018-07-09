#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(20, vector<int>(500000, -1));
vector<vector<pair<int,int>>> adj(20);
int n;

int dfs(int u, int vis)
{
 vis |= 1<<u;
 if (~dp[u][vis]) return dp[u][vis];
 dp[u][vis] = 0; 
 for (auto &x : adj[u])
  if (!((vis>>x.first)&1))
   dp[u][vis] = max(dp[u][vis], dfs(x.first, vis)+x.second);
    if (!dp[u][vis] && u ^ (n-1)) return dp[u][vis] = INT_MIN;
 return dp[u][vis];
}

int main()
{
 int m, a, b, c;
 scanf("%i%i", &n, &m);
 while (m--)
 {
  scanf("%i%i%i", &a, &b, &c);
  adj[a].push_back({b, c});
 }
 printf("%i", dfs(0, 0));
}
