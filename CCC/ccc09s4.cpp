#include <bits/stdc++.h>

using namespace std;

vector<int> sellPencil;
int minCost;

class Graph
{
    int V;
    typedef pair<int,int> iPair;
    vector<iPair> *adj;
    int *dist;
    bool *vis;

public:
    Graph(int);
    ~Graph();
    int* graphBFS(int);
    void uAddEdge(int, int, int);
    void uAddEdge(int, int);
    void dAddEdge(int, int, int);
    void dAddEdge(int, int);
    void reset();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<iPair> [V];
    dist = new int[V];
    vis = new bool[V];
    reset();
}

Graph::~Graph()
{
    delete []adj;
    delete []dist;
    delete []vis;
}

void Graph::uAddEdge (int node1, int node2, int weight)
{
    adj[node1].push_back(make_pair(node2, weight));
    adj[node2].push_back(make_pair(node1, weight));
}

void Graph::uAddEdge (int node1, int node2)
{
    adj[node1].push_back(make_pair(node2, 1));
    adj[node2].push_back(make_pair(node1, 1));
}

void Graph::dAddEdge (int node1, int node2, int weight)
{
    adj[node1].push_back(make_pair(node2, weight));
}

void Graph::dAddEdge (int node1, int node2)
{
    adj[node1].push_back(make_pair(node2, 1));
}

void Graph::reset()
{
    for (int x = 0; x < V; x++)
        dist[x] = INT_MAX, vis[x] = false, adj[x].clear();
}

int* Graph::graphBFS (int src)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> buf;
    dist[src] = 0;
    vis[src] = true;
    buf.push(make_pair(0, src));
    while (!buf.empty())
    {
        int u = buf.top().second;
        vis[u] = false;
        buf.pop();
        for (int x = 0; x < adj[u].size(); x++)
        {
            if (dist[u] + adj[u][x].second < dist[adj[u][x].first])
            {
                dist[adj[u][x].first] = dist[u] + adj[u][x].second;
                if (sellPencil[adj[u][x].first] != -1)
                    minCost = min(dist[adj[u][x].first]+sellPencil[adj[u][x].first], minCost);
                if (!vis[adj[u][x].first])
                {
                    vis[adj[u][x].first] = true;
                    buf.push(make_pair(dist[adj[u][x].first], adj[u][x].first));
                }
            }
        }
    }
    return dist;
}

int main()
{
    int n, t, a, b, c, k, z, p, d;
    scanf("%i", &n);
    sellPencil.resize(n+1, -1);
    Graph g(n+1);
    scanf("%i", &t);
    for (int x = 0; x < t; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        g.uAddEdge(a, b, c);
    }
    scanf("%i", &k);
    for (int x = 0; x < k; x++)
    {
        scanf("%i%i", &z, &p);
        sellPencil[z] = p;
    }
    scanf("%i", &d);
    minCost = sellPencil[d] != -1 ? sellPencil[d] : INT_MAX;
    g.graphBFS(d);
    printf("%i", minCost);
    return 0;
}
