#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> numCherries (10005);

class Graph
{
public:
    Graph(int);
    vector<pair<int,int>> Util();

    inline void uAddEdge (const int node1, const int node2, const int weight)
    {
        adj[node1].push_back(make_pair(node2, weight));
        adj[node2].push_back(make_pair(node1, weight));
    }

private:
    int V;
    vector<vector<pair<int,int>>> adj;
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

vector<pair<int,int>> Graph::Util()
{
    vector<pair<int,int>> sum (V);
    for (int x = 0; x < V; x++)
        sum[x] = make_pair(0,numCherries[x].first);
    for (int x = V-1; x > 0; x--)
    {
        for (auto &y : adj[x])
        {
            if (y.first > x)
                sum[x].first+=sum[y.first].first+y.second, sum[x].second+=sum[y.first].second;
            else
                numCherries[x].second = y.second;
        }
    }
    return sum;
}

int main()
{
    int n, c, k, a, b, w, t = 0;
    scanf("%i%i%i", &n, &c, &k);
    Graph g (n+1);
    for (int x = 1; x <= n; x++)
        scanf("%i", &numCherries[x].first);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i%i", &a, &b, &w);
        g.uAddEdge(a, b, w);
    }
    vector<pair<int,int>> s = g.Util();
    for (int x = 2; x < n+1; x++)
    {
        if (s[x].first+numCherries[x].second <= k && s[x].second >= c)
            t++;
    }
    printf("%i", t);
    return 0;
}
