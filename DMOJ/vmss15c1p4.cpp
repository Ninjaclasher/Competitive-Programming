#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
    int V;
    vector<pair<int, int>> *adj;

public:
    Graph(int V);
     void addEdge(int u, int v, int w);
     int* shortestPath();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

int* Graph::shortestPath()
{
    priority_queue<iPair, vector <iPair> , greater<iPair>> pq;
    bool sptSet[V] = {1};
    int *dist = new int[V];
    for (int x = 1; x < V; x++)
        dist[x] = 1000000000;
    dist[0] = 0;
    pq.push(make_pair(0, 0));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        vector<pair<int, int>>::iterator i;
        sptSet[u] = false;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                if (!sptSet[v])
                {
                    sptSet[v] = true;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
    return dist;
}

int main()
{
    int t, n, m, g, a, b, l, c = 0;
    scanf("%i%i%i%i", &t, &n, &m, &g);
    Graph s(m+1);
    int shops[g];
    for (int x = 0; x < g; x++)
        scanf("%i", &shops[x]);
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i%i", &a, &b, &l);
        s.addEdge(a, b, l);
    }
    int *dist = new int [m+1];
    dist = s.shortestPath();
    for (int x = 0; x < g; x++)
        if (dist[shops[x]] <= t) c++;
    printf("%i", c);
    return 0;
}
