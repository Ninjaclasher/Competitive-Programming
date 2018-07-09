#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<pair<int,int>>> geoPos;

class Graph
{
public:
    Graph(int);
    vector<int> graphBFS(int, int);

    inline void uAddEdge (const int node1, const int node2, const int weight)
    {
        adj[node1][node2] = weight;
        adj[node2][node1] = weight;
    }
    inline void uAddEdge (const int node1, const int node2)
    {
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;
    }

private:
    int V;
    vector<int> dist;
    vector<bool> vis;
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V), dist.resize(V, INT_MAX), vis.resize(V), geoPos.resize(V);
    for (auto &x : adj)
        x.resize(V, INT_MAX);
    for (auto &x : geoPos)
        x.resize(V, make_pair(INT_MAX, 0));
}

vector<int> Graph::graphBFS (int src, int strtTm)
{
    queue<int> buf;
    dist[src] = strtTm;
    vis[src] = true;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        vis[u] = false;
        buf.pop();
        for (int y = 0; y < V; y++)
        {
            if (adj[u][y] != INT_MAX)
            {
                int x = adj[u][y];
                int fast = (geoPos[u][y].first <= dist[u] && geoPos[u][y].second >= dist[u]? geoPos[u][y].second : 0);
                if (max(fast, dist[u]) + x < dist[y])
                {
                    dist[y] = max(fast, dist[u]) + x;
                    if (!vis[y])
                    {
                        vis[y] = true;
                        buf.push(y);
                    }
                }
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, a, b, k, g, q, w, t;
    scanf("%i%i%i%i%i%i", &n, &m, &a, &b, &k, &g);
    Graph gr (n+1);
    vector<int> geoRoute(g);
    for (int x = 0; x < g; x++)
        scanf("%i", &geoRoute[x]);
    while (m--)
    {
        scanf("%i%i%i", &q, &w, &t);
        gr.uAddEdge(q, w, t);
    }
    for (int x = 0, c = 1; x < geoRoute.size()-1; x++)
    {
        geoPos[geoRoute[x]][geoRoute[x+1]] = make_pair(c, c+adj[geoRoute[x]][geoRoute[x+1]]-1);
        geoPos[geoRoute[x+1]][geoRoute[x]] = make_pair(c, c+adj[geoRoute[x]][geoRoute[x+1]]-1);
        c+=adj[geoRoute[x]][geoRoute[x+1]];
    }

    vector<int> aa = gr.graphBFS(a, k);
    printf("%i\n", aa[b]-k);

    return 0;
}
