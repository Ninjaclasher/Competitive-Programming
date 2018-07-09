#include <bits/stdc++.h>

using namespace std;

struct path
{
    int b, weight;
    bool sunshine;
    path (int bb, int ww, bool ss)
    {
        b = bb, weight = ww, sunshine = ss;
    }
};


class Graph
{
public:
    Graph(int, int);
    vector<vector<int>> graphBFS(int);

    inline void uAddEdge (const int node1, const int node2, const int weight, const bool ss)
    {
        adj[node1].push_back(path(node2, weight, ss));
        adj[node2].push_back(path(node1, weight, ss));
    }
private:
    int V;
    int E;
    vector<vector<path>> adj;
    vector<vector<int>> dist;
    vector<bool> vis;
};

Graph::Graph(int V, int E)
{
    this->V = V, this->E = E;
    adj.resize(V), dist.resize(V), vis.resize(V);
    for (auto &x : adj) x.clear();
    for (auto &x : dist) x.resize(E+1, INT_MAX);
    fill (vis.begin(), vis.end(), false);
}

vector<vector<int>> Graph::graphBFS (int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> buf;
    dist[src][0] = 0;
    vis[src] = true;
    buf.push(make_pair(0, src));
    while (!buf.empty())
    {
        int u = buf.top().second;
        vis[u] = false;
        buf.pop();
        for (int y = 0; y <= E; y++)
        {
            if (dist[u][y] != INT_MAX)
            {
                for (auto &x : adj[u])
                {
                    int tmpDist = dist[u][y] + x.weight, sun = y+(x.sunshine ? x.weight : 0);
                    if (sun <= E && tmpDist < dist[x.b][sun])
                    {
                        dist[x.b][sun] = tmpDist;
                        if (!vis[x.b])
                        {
                            vis[x.b] = true;
                            buf.push(make_pair(dist[x.b][sun], x.b));
                        }
                    }
                }
            }
        }
    }
    return dist;
}

int main()
{
    int s, n, e, a, b, d, u;
    scanf("%i%i%i", &s, &n, &e);
    Graph g (n, s);
    while (e--)
    {
        scanf("%i%i%i%i", &a, &b, &d, &u);
        g.uAddEdge(a, b, d, u);
    }
    vector<vector<int>> dists = g.graphBFS(0);
    int minDis = INT_MAX;
    for (auto &x : dists[n-1])
        minDis = min(minDis, x);
    printf("%i\n", minDis == INT_MAX ? -1 : minDis);
    return 0;
}
