#include <bits/stdc++.h>

using namespace std;

int *dist;

class Graph
{
    int V;
    typedef pair<int,int> iPair;
    vector<iPair> *adj;
    int *rnk, *parent;
    bool *vis;

    void cycleUtil(int, bool*);
public:
    Graph(int);
    ~Graph();
    void graphBFS(int);
    int DisjointSetFind(int);
    void DisjointSetMerge(int, int);
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
    dist = new int[V], rnk = new int[V], parent = new int[V];
    vis = new bool[V];
    reset();
}

Graph::~Graph()
{
    delete []adj;
    delete []dist;
    delete []rnk;
    delete []parent;
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
        dist[x] = INT_MAX, rnk[x] = 0, parent[x] = x, vis[x] = false, adj[x].clear();
}

void Graph::graphBFS (int src)
{
    for (int x = 0; x < V; x++)
        dist[x] = INT_MAX, vis[x] = false;
    priority_queue<iPair,vector<iPair>,greater<iPair>> buf;
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
                if (!vis[adj[u][x].first])
                {
                    vis[adj[u][x].first] = true;
                    buf.push(make_pair(dist[adj[u][x].first], adj[u][x].first));
                }
            }
        }
    }
}

int Graph::DisjointSetFind(int node)
{
    if (node != parent[node])
        parent[node] = DisjointSetFind(parent[node]);
    return parent[node];
}

void Graph::DisjointSetMerge(int node1, int node2)
{
    node1 = DisjointSetFind(node1), node2 = DisjointSetFind(node2);
    if (rnk[node1] > rnk[node2])
        parent[node2] = node1;
    else
        parent[node1] = node2;
    if (rnk[node1] == rnk[node2])
        rnk[node2]++;
}

int main()
{
    int v, e, p, d, r, a, b, c;
    scanf("%i%i%i%i%i", &v, &e, &p, &d, &r);
    Graph g(v+1);
    for (int x = 0; x < e; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        g.DisjointSetMerge(a, b);
        g.uAddEdge(a, b, c);
    }
    if (g.DisjointSetFind(d) != g.DisjointSetFind(p))
    {
        printf("Nooooooooo!!!");
        return 0;
    }
    g.graphBFS(p);
    int tmp = 3;
    int greaterCost = 10;
    if (dist[d] <= 10)
        tmp += dist[d]*2, greaterCost -= dist[d], dist[d] = 0;
    if (dist[d])
    {
        tmp += 20;
        tmp += dist[d] - 10;
        greaterCost = 0;
    }
    if (g.DisjointSetFind(r) != g.DisjointSetFind(p))
    {
        printf("%i\nYippee!!!", tmp);
        return 0;
    }
    g.graphBFS(d);
    tmp += dist[r];
    printf("%i", tmp);
    return 0;
}
