#include <bits/stdc++.h>

using namespace std;

typedef pair<unsigned long long, unsigned long long> iPair;

int n, a, b, src, q;
vector<unsigned long long> dist;
unsigned long long adj[3001][3001];

class Graph
{
    int V;
    bool *vis;

public:
    Graph(int);
    void graphBFS();
};

Graph::Graph(int V)
{
    this->V = V;
    dist.resize(V);
    vis = new bool[V];
    for (long long x = 0; x < V; x++)
        dist[x] = LONG_MAX;
}


void Graph::graphBFS()
{
    dist[src] = 0;
    vis[src] = true;
    int discovered = 1, lastadded = src;
    while(discovered<V)
    {
        vis[lastadded] = true;
        for (int i = 0; i < V; i++)
            dist[i] = min(dist[i],dist[lastadded]+adj[lastadded][i]);
        long long mincost = LONG_MAX;
        int mincostindex = -1;
        for(int i=1;i<V;i++)
        {
            if(dist[i]<mincost && !vis[i])
            {
                mincostindex = i;
                mincost = dist[i];
            }
        }
        if(mincost==LONG_MAX) break;
        lastadded = mincostindex;
        discovered++;
    }
}

int main()
{
    vector<pair<unsigned long long, unsigned long long>> pos;
    long long hours;
    scanf("%i", &n);
    Graph g(n+1);
    pos.resize(n+1);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i%i", &a, &b);
        pos[x] = make_pair(a, b);
    }
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            adj[x][y] = ((pos[x].first-pos[y].first)*(pos[x].first-pos[y].first)) + ((pos[x].second-pos[y].second)*(pos[x].second-pos[y].second));
    scanf("%i", &src);
    g.graphBFS();
    sort (dist.begin(), dist.end());
    scanf("%i", &q);
    while (q--)
    {
        scanf("%lli", &hours);
        vector<unsigned long long>::iterator p = upper_bound(dist.begin(), dist.end(), hours);
        printf("%i\n", p-dist.begin()-1);
    }
    return 0;
}
