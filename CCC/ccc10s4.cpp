#include <bits/stdc++.h>

using namespace std;


class disjoint_set
{
public:
    disjoint_set(int);
    int Find(int);
    void Merge(int,int);

private:
    vector<int> rnk, parent;
    int V;
};

class Graph
{
public:
    Graph(int);
    int MST();
    inline void mAddEdge (const int node1, const int node2, const int weight)
        { unprocessedEdges.push_back(make_pair(weight, make_pair(node1, node2)));}

private:
    int V;
    vector<pair<int,pair<int,int>>> unprocessedEdges;
};

disjoint_set::disjoint_set(int V)
{
    this->V = V;
    rnk.resize(V, 0), parent.resize(V);
    int n = 0;
    generate(parent.begin(), parent.end(), [&n] () {return n++;});
}

int disjoint_set::Find(int node)
{
    if (node != parent[node]) parent[node] = Find(parent[node]);
    return parent[node];
}

void disjoint_set::Merge(int node1, int node2)
{
    node1 = Find(node1), node2 = Find(node2);
    if (rnk[node1] > rnk[node2]) parent[node2] = node1;
    else parent[node1] = node2;
    if (rnk[node1] == rnk[node2]) rnk[node2]++;
}

Graph::Graph(int V)
{
    this->V = V;
}

int Graph::MST()
{
    int total = 0;
    disjoint_set ds (V);
    sort(unprocessedEdges.begin(), unprocessedEdges.end());
    for (auto &x : unprocessedEdges)
    {
        int set1 = ds.Find(x.second.first), set2 = ds.Find(x.second.second);
        if (set1 != set2)
        {
            total += x.first;
            ds.Merge(set1, set2);
        }
    }
    return total;
}

int main()
{
    vector<vector<int>> edges(200,vector<int>(200,-1));
    vector<vector<pair<int,int>>> idx(200,vector<pair<int,int>>(200,make_pair(-1,-1)));
    int n, e, w;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &e);
        vector<int> aa(e);
        for (int y = 0; y < e; y++)
            scanf("%i", &aa[y]);
        for (int y = 0; y < e; y++)
        {
            scanf("%i", &w);
            int ne = (y+1==e ? 0 : y+1);
            edges[aa[y]][aa[ne]] = edges[aa[ne]][aa[y]] = min(w, edges[aa[ne]][aa[y]]==-1 ? INT_MAX : edges[aa[ne]][aa[y]]);
            if (idx[aa[ne]][aa[y]].first==-1)
                idx[aa[y]][aa[ne]].first = idx[aa[ne]][aa[y]].first = x;
            else
                idx[aa[y]][aa[ne]].second = idx[aa[ne]][aa[y]].second = x;
        }
    }
    Graph g (200);
    for (int x = 0; x < 200; x++)
        for (int y = 0; y < 200; y++)
            if (idx[x][y].first != -1 && idx[x][y].second != -1)
                g.mAddEdge(idx[x][y].first, idx[x][y].second, edges[x][y]);
    int to = g.MST();
    for (int x = 0; x < 200; x++)
        for (int y = 0; y < 200; y++)
            if (idx[x][y].first != -1 && idx[x][y].second == -1)
                g.mAddEdge(idx[x][y].first, 199, edges[x][y]);
    printf("%i", min(to, g.MST()));


}
