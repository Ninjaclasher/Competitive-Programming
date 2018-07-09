#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(2005);
vector<int> dist(2005, INT_MAX);

int main()
{
 int n, m, q, a, b, c, d, e;
 scanf("%i%i%i%i", &n, &m, &d, &q);
 while (m--)
 {
  scanf("%i%i%i", &a, &b, &c);
  adj[a].push_back({b, c});
  adj[b].push_back({a, c});
 }
 dist[d] = 0;
 queue<int> buf;
 buf.push(d);
 while (!buf.empty())
 {
  int u = buf.front();
  buf.pop();
  for (auto &x : adj[u])
   if (dist[x.first] > dist[u]+x.second)
    dist[x.first] = dist[u]+x.second, buf.push(x.first);
 }
 while (q--)
 {
  scanf("%i", &e);
  printf("%i\n", dist[e] == INT_MAX ? -1 : dist[e]);
 }
}
