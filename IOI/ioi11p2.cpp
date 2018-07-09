#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(200005);
vector<int> sz(200005), val(1000010, INT_MAX);
vector<bool> vis(200005);
vector<pair<int,int>> tmp;
int mi = INT_MAX, used[300005];

int dfs(int u, int p)
{
 sz[u] = 1;
 for (auto &x : adj[u])
  if (x.first ^ p && !vis[x.first])
   sz[u] += dfs(x.first, u);
 return sz[u];
}

void dfs2(int u, int p, int l, int c, int k)
{
 if (k-l < 0)
  return;
 if (val[k-l] != INT_MAX)
  mi = min(mi, val[k-l]+c);
 tmp.push_back({l, c});
 for (auto &x : adj[u])
  if (x.first ^ p && !vis[x.first])
   dfs2(x.first, u, l+x.second, c+1, k);
}

int centroid(int u, int p, int nn)
{
 for (auto &x : adj[u])
  if (x.first ^ p && !vis[x.first] && sz[x.first]*2 > nn)
   return centroid(x.first, u, nn);
 return u;
}

void solve(int u, int k)
{
 dfs(u,u);
 u = centroid(u, u, sz[u]);
 vis[u] = true;
 int c = 0;
 for (auto &x : adj[u])
 {
  if (!vis[x.first])
  {
   tmp.clear();
   dfs2(x.first, u, x.second, 1, k);
   for (auto &y : tmp)
    if (y.first <= k)
     val[y.first] = min(val[y.first], y.second), used[++c] = y.first;
  }
 }
 mi = min(mi, val[k]);
 for (; c; c--)
  val[used[c]] = INT_MAX;
 for (auto &x : adj[u])
  if (!vis[x.first])
   solve(x.first, k);
}

int best_path(int N, int K, int H[][2], int L[])
{
 for (int x = 0; x < N-1; x++)
  adj[H[x][0]].push_back({H[x][1], L[x]}), adj[H[x][1]].push_back({H[x][0], L[x]});
 solve(1, K);
 return mi == INT_MAX ? -1 : mi;
}
