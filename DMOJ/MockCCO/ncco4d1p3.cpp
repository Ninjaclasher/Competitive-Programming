#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    Graph(int);
    vector<pair<int,int>> graphBFS(int);

    inline void dAddEdge (const short node1, const short node2, const short weight)
        { adj[node1].push_back(make_pair(node2, weight));}

private:
    int V;
    vector<vector<pair<short,short>>> adj;
    vector<pair<int,int>> dist;
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V), dist.resize(V, make_pair(INT_MAX, INT_MAX));
}

vector<pair<int,int>> Graph::graphBFS (int src)
{
    queue<int> buf;
    dist[src] = make_pair(0,INT_MAX);
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
        {
            if (dist[u].first + x.second <= dist[x.first].first)
            {
                if (dist[u].first + x.second != dist[x.first].first)
                {
                    dist[x.first].second = dist[x.first].first;
                    dist[x.first].first = dist[u].first + x.second;
                    buf.push(x.first);
                }
            }
            else if (dist[u].first + x.second < dist[x.first].second)
            {
                dist[x.first].second = dist[u].first + x.second;
                buf.push(x.first);
            }
            if (dist[u].second != INT_MAX && dist[u].second + x.second < dist[x.first].second)
            {
                dist[x.first].second = dist[u].second + x.second;
                buf.push(x.first);
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, a, b, c;
    scanf("%i%i", &n, &m);
    Graph g (n+1);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        g.dAddEdge(a, b, c);
        g.dAddEdge(b, a, c);

    }
    vector<pair<int,int>> qq = g.graphBFS(1);
    printf("%i\n", qq[n].second == INT_MAX ? -1 : qq[n].second);

    return 0;
}
