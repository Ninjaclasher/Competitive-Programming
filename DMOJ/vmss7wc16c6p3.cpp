#include<bits/stdc++.h>
using namespace std;

vector<int> points;
 
class Graph
{
    int V;
    vector<int> *adj;
    void APUtil(int v);

    bool *visited;
    int *disc;
    int *low;
    int *parent;
    bool *ap;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void AP();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];

    visited = new bool[V];
    disc = new int[V];
    low = new int[V];
    parent = new int[V];
    ap = new bool[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::APUtil(int u)
{
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v);
            low[u]  = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1)
               ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])
               ap[u] = true;
        }
         else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
void Graph::AP()
{
    for (int i = 0; i < V; i++)
        parent[i] = -1;
    for (int i = 0; i < V; i++)
        if (!visited[i]) APUtil(i);
    for (int i = 0; i < V; i++)
        if (ap[i]) points.push_back(i);
}

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    Graph g (n+1);
    while (m--)
    {
        int a,b;
        scanf("%i%i", &a, &b);
        g.addEdge(a,b);
    }
    g.AP();
    printf("%i\n", points.size());
    for (int x = 0; x < points.size(); x++)
        printf("%i\n", points[x]);
    return 0;
}
