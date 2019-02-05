#include <bits/stdc++.h>

using namespace std;

int dist[4000001];
int selfDist[4000001];
int k = INT_MIN;

class Graph
{
    int V;
    typedef pair<int,int> iPair;
    vector<iPair> *adj;
public:
    Graph(int);
    void graphBFS(int);
    void dAddEdge(int, int, int);
    void dAddEdge(int, int);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<iPair> [V];
}

void Graph::dAddEdge (int node1, int node2, int weight)
{
    adj[node1].push_back(make_pair(node2, weight));
}

void Graph::dAddEdge (int node1, int node2)
{
    adj[node1].push_back(make_pair(node2, 1));
}

void Graph::graphBFS (int src)
{
    queue<int> buf;
    buf.push(src);
    k = max(k, dist[src]);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (int x = 0; x < adj[u].size(); x++)
        {
            dist[adj[u][x].first] += selfDist[src];
            buf.push(adj[u][x].first);
        }
    }
}

int main()
{
    int n, a, b, c;
    scanf("%i", &n);
    Graph g(n+1);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        g.dAddEdge(b, a);
    }
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &c);
        selfDist[x] = dist[x] = c;
    }
    for (int x = n; x > 0; x--)
        g.graphBFS(x);
    printf("%i", k);
    return 0;
}
