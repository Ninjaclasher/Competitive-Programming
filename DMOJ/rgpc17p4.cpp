#include <bits/stdc++.h>

using namespace std;

int dist[1001];
int points[1001];

typedef pair<int, int> iPair;

class Path
{
    int V;
    vector<iPair> *adj;

public:
    Path(int V);
     void addEdge(int u, int v, int w);
     void shortestPath();
     bool isCyclic();
     bool isCyclicUtil(int, bool*, bool*);
};

Path::Path(int V)
{
    this->V = V;
    adj = new vector<iPair> [V];
}

void Path::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

void Path::shortestPath()
{
    queue<int> pq;
    dist[1] = 0;
    points[1] = 1;
    pq.push(1);
    while (!pq.empty())
    {
        int u = pq.front();
        pq.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (dist[adj[u][i].first] < dist[u] + adj[u][i].second)
            {
                points[adj[u][i].first] = points[u] + 1;
                dist[adj[u][i].first] = dist[u] + adj[u][i].second;
                pq.push(adj[u][i].first);
            }
            else if (dist[adj[u][i].first] == dist[u] + adj[u][i].second)
                points[adj[u][i].first] = max(points[u]+1, points[adj[u][i].first]);
        }
    }
}

bool Path::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if (!visited[v])
    {
        visited[v] = true, recStack[v] = true;
        for(int i = 0; i < adj[v].size(); i++)
        {
            if (!visited[i] && isCyclicUtil(i, visited, recStack))
                return true;
            else if (recStack[i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool Path::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false, recStack[i] = false;
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
    return false;
}

int main()
{
    int n, m, a, b, w;
    scanf("%i%i", &n, &m);
    Path g(n+1);
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i%i", &a, &b, &w);
        g.addEdge(a, b, w);
    }
    if (!g.isCyclic()) printf("-1");
    else
    {
        g.shortestPath();
        if (!dist[n] || dist[n] > 2147438900) printf("-1");
        else printf("%i %i", dist[n], points[n]);
    }
    return 0;
}
