#include<bits/stdc++.h>
using namespace std;

int dist[1001][1001];

class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int V);
     void addEdge(int u, int v);
     void shortestPath(int);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int> [V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::shortestPath(int src)
{
    priority_queue<int, vector <int> , greater<int>> pq;
    dist[src][src] = 0;
    pq.push(src);
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (dist[src][adj[u][i]] > dist[src][u] + 1)
            {
                dist[src][adj[u][i]] = dist[src][u] + 1;
                pq.push(adj[u][i]);
            }
        }
    }
}

int main()
{
    for (int x = 0; x < 1001; x++)
        for (int y = 0; y < 1001; y++)
        dist[x][y] = 100000000;
    int n, m, t, q, a, b;
    scanf("%i%i%i", &n, &m, &t);
    Graph g(n+1);
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i", &a, &b);
        g.addEdge(a-1, b-1);
    }
 while (n) g.shortestPath(--n);
    scanf("%i", &q);
    for (int x = 0; x < q; x++)
    {
        scanf("%i%i", &a, &b);
        if (dist[a-1][b-1] == 100000000)
            printf("Not enough hallways!\n");
        else
            printf("%i\n", dist[a-1][b-1]*t);
    }
    return 0;
}
