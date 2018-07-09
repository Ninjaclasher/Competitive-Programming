#include <bits/stdc++.h>

using namespace std;

vector<pair<int,double>> dist;

class Graph
{
public:
    Graph(int);
    void graphBFS();

    inline void uAddEdge (const int node1, const int node2, const double t)
    {
        adj[node1].push_back(make_pair(node2, t));
        adj[node2].push_back(make_pair(node1, t));
    }

private:
    int V;
    vector<vector<pair<int,double>>> adj;
    vector<bool> vis;
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V), vis.resize(V, false);
    dist.resize(V, make_pair(INT_MAX, INT_MAX));
}

void Graph::graphBFS()
{
 queue<int> buf;
 dist[1] = make_pair(0,0);
    vis[1] = true;
    buf.push(1);
    while (!buf.empty())
    {
        int u = buf.front();
        vis[u] = false;
        buf.pop();
        for (auto &x : adj[u])
        {
   double time = x.second*60;
   if (dist[u].second + time < dist[x.first].second || (dist[u].second + time == dist[x.first].second && dist[u].first < dist[x.first].first))
   {
    dist[x.first].second = dist[u].second+time;
    dist[x.first].first = dist[u].first+1;
    if (!vis[x.first])
    {
     vis[x.first] = true;
     buf.push(x.first);
    }
   }
        }
    }
}

int main()
{
    int v, e, a, b, d, s;
 scanf("%i%i", &v, &e);
 Graph g (v+1);
 while (e--)
 {
  scanf("%i%i%i%i", &a, &b, &d, &s);
  g.uAddEdge(a, b, static_cast<double>(d)/s);
 }
 g.graphBFS();
 printf("%i\n%.0f", dist[v].first, round(dist[v].second/3));
    return 0;
}
