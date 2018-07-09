#include <bits/stdc++.h>

using namespace std;

unordered_map <string,int> nodeNames;
double adj[500][500];

class Graph
{
    int V;
    typedef pair<int,int> iPair;
    double *dist;

public:
    Graph(int);
    bool graphBFS(int);
};

Graph::Graph(int V)
{
    this->V = V;
    dist = new double[V];
}

bool Graph::graphBFS (int src)
{
    queue<int> buf;
    dist[src] = 1;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (int x = 0; x < V; x++)
        {
            if (round(dist[u] * adj[u][x]*10000000000)/10000000000 > dist[x])
            {
                if (x == src)
                    return true;
                dist[x] = round(dist[u] * adj[u][x]*10000000000)/10000000000;
                buf.push(x);
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    double tmpVal;
    scanf("%i%i", &n, &m);
    Graph g (n);
    string tmpName1, tmpName2;
    for (int x = 0; x < n; x++)
    {
        cin>>tmpName1;
        nodeNames.insert(make_pair(tmpName1,x));
    }
    for (int x = 0; x < m; x++)
    {
        cin>>tmpName1>>tmpName2;
        scanf("%lf", &tmpVal);
        adj[nodeNames[tmpName1]][nodeNames[tmpName2]] = max(adj[nodeNames[tmpName1]][nodeNames[tmpName2]], tmpVal);
    }
    if (g.graphBFS(nodeNames["APPLES"]))
        goto ya;
    else
        goto naw;
    return 0;
    naw:
    printf("NAW");
    return 0;
    ya:
    printf("YA");
    return 0;
}
