#include <bits/stdc++.h>

using namespace std;

vector<bool> dd (10000000, true);

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
    vector<double> graphBFS(int);
    vector<vector<int>> gridBFS(const vector<vector<char>> &, const char, const int, const int);
    vector<vector<int>> gridBFS(const vector<vector<char>> &, const char, const vector<pair<int,int>> &, const int, const int);
    void MST();
    vector<vector<int>> getCyclesRecursive();
    vector<vector<int>> getCyclesIterative();
    vector<pair<int,int>> getBridges();
    vector<int> getArticulationPoints();
    void reset();
    void resetAll();

    inline void uAddEdge (const int node1, const int node2, const int weight)
    {
        adj[node1].push_back(make_pair(node2, weight));
        adj[node2].push_back(make_pair(node1, weight));
    }
    inline void uAddEdge (const int node1, const int node2)
    {
        adj[node1].push_back(make_pair(node2, 1));
        adj[node2].push_back(make_pair(node1, 1));
    }
    inline void dAddEdge (const int node1, const int node2, const int weight)
        { adj[node1].push_back(make_pair(node2, weight));}
    inline void dAddEdge (const int node1, const int node2)
        { adj[node1].push_back(make_pair(node2, 1));}
    inline void mAddEdge (const int node1, const int node2, const int weight)
        { unprocessedEdges.push_back(make_pair(weight, make_pair(node1, node2)));}

private:
    int V;
    vector<vector<pair<int,int>>> adj;
    vector<pair<int,pair<int,int>>> unprocessedEdges;
    vector<vector<int>> storedCycles;
    vector<double> dist;
    vector<bool> vis;
    void rCycleUtil(int, vector<int> &);
    void bridgeUtil(int, vector<pair<int,int>> &, vector<int> &, vector<pair<int,int>> &);
    void APUtil(int, vector<pair<int,int>> &, vector<int> &, vector<int> &);
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
    adj.resize(V), dist.resize(V), vis.resize(V);
    resetAll();
}

void Graph::resetAll()
{
    for (auto &x : adj) x.clear();
    unprocessedEdges.clear();
    reset();
}

void Graph::reset()
{
    storedCycles.clear();
    fill(dist.begin(), dist.end(), 0);
    fill(vis.begin(), vis.end(), false);
}

vector<double> Graph::graphBFS (int src)
{
    dist[src] = 1;
/*    queue<int> buf;
    dist[src] = 1;
    vis[src] = true;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        double d = dist[u] / adj[u].size();
        if (!adj[u].empty())
            dd[u] = false;
        for (auto &x : adj[u])
        {
            dist[x.first] += d;
            if (!vis[x.first])
            {
                vis[x.first] = true;
                buf.push(x.first);
            }
        }
    }
    return dist;*/
    for (int x = 1; x < V; x++)
    {
        double d = dist[x] / adj[x].size();
        if (!adj[x].empty())
            dd[x] = false;
        for (auto &y : adj[x])
            dist[y.first]+=d;
    }
    return dist;
}

vector<vector<int>> Graph::gridBFS(const vector<vector<char>> &grid, const char wall, const vector<pair<int,int>> &relativeMove, const int srcX, const int srcY)
{
    reset();
    vector<vector<int>> dists (grid.size());
    for (auto &x : dists) x.resize(grid[0].size(), INT_MAX);
    vector<vector<bool>> visited (grid.size());
    for (auto &x : visited) x.resize(grid[0].size(), false);
    dists[srcX][srcY] = 0;
    queue <pair<int,int>> buf;
    buf.push(make_pair(srcX, srcY));
    while (!buf.empty())
    {
        int x = buf.front().first, y = buf.front().second;
        buf.pop();
        for (auto &i : relativeMove)
        {
            if (grid[x+i.first][y+i.second] != wall && dists[x][y] + 1 < dists[x+i.first][y+i.second])
            {
                dists[x+i.first][y+i.second] = dists[x][y] + 1;
                if (!visited[x+i.first][y+i.second])
                {
                    visited[x+i.first][y+i.second] = true;
                    buf.push(make_pair(x+i.first, y+i.second));
                }
            }
        }
    }
    return dists;
}

vector<vector<int>> Graph::gridBFS(const vector<vector<char>> &grid, const char wall, const int srcX, const int srcY)
{
    vector<pair<int,int>> moveIteration = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1),
                                           make_pair(1,1), make_pair(-1,1), make_pair(-1,1), make_pair(-1,-1)};
    return gridBFS(grid, wall, moveIteration, srcX, srcY);
}

void Graph::MST()
{
    reset();
    for (auto &x : adj) x.clear();
    disjoint_set ds (V);
    sort(unprocessedEdges.begin(), unprocessedEdges.end());
    for (auto &x : unprocessedEdges)
    {
        int set1 = ds.Find(x.second.first), set2 = ds.Find(x.second.second);
        if (set1 != set2)
        {
            uAddEdge(x.second.first, x.second.second, x.first);
            ds.Merge(set1, set2);
        }
    }
}

void Graph::rCycleUtil(int pos, vector <int> &cycleTmp)
{
    if (vis[pos])
    {
        vector<int> ss;
        for (auto i = find (cycleTmp.begin(), cycleTmp.end(), pos); i != cycleTmp.end(); i++) ss.push_back(*i);
        if (find(storedCycles.begin(), storedCycles.end(), ss) == storedCycles.end()) storedCycles.push_back(ss);
        return;
    }
    cycleTmp.push_back(pos);
    vis[pos] = true;
    for (auto &x : adj[pos]) rCycleUtil(x.first, cycleTmp);
    vis[pos] = false;
    cycleTmp.pop_back();
}

vector<vector<int>> Graph::getCyclesRecursive()
{
    reset();
    vector <int> cycleTmp;
    for (int x = 0; x < V; x++)
        rCycleUtil(x, cycleTmp);
    sort (storedCycles.begin(), storedCycles.end());
    return storedCycles;
}

vector<vector<int>> Graph::getCyclesIterative()
{
    reset();
    stack<vector<int>> buf;
    for (int i = 0; i < V; i++)
    {
        buf.push (vector<int> {i});
        while (!buf.empty())
        {
            vector<int> tmp = buf.top();
            buf.pop();
            int v = tmp.back();
            for (auto &x : adj[v])
            {
                bool found = false;
                vector<int> ss;
                for (auto &y : tmp)
                {
                    if (x.first == y) found = true;
                    if (found) ss.push_back(y);
                }
                if (found && find(storedCycles.begin(), storedCycles.end(), ss) == storedCycles.end())
                    storedCycles.push_back(ss);
                tmp.push_back(x.first);
                if (!found) buf.push(tmp);
                tmp.pop_back();
            }
        }
    }
    sort (storedCycles.begin(), storedCycles.end());
    return storedCycles;
}

void Graph::bridgeUtil(int u, vector<pair<int,int>> &times, vector<int> &parent, vector<pair<int,int>> &bridges)
{
    static int time = 0;
    vis[u] = true;
    times[u] = make_pair(++time, time);
 
    for (auto &x : adj[u])
    { 
        if (!vis[x.first])
        {
            parent[x.first] = u;
            bridgeUtil(x.first, times, parent, bridges);
            times[u].first = min(times[u].first, times[x.first].first);
            if (times[x.first].first > times[u].second)
                bridges.push_back(make_pair(u, x.first));
        }
        else if (x.first != parent[u])
            times[u].first  = min(times[u].first, times[x.first].second);
    }
}

vector<pair<int,int>> Graph::getBridges()
{
    reset();
    vector<pair<int,int>> times (V, make_pair(0,0));
    vector<int> parent (V, -1);
    vector<pair<int,int>> bridges;

    for (int i = 0; i < V; i++)
        if (!vis[i])
            bridgeUtil(i, times, parent, bridges);
    sort (bridges.begin(), bridges.end());
    return bridges;
}

void Graph::APUtil(int u, vector<pair<int,int>> &times, vector<int> &parent, vector<int> &articulationPoints)
{
    static int time = 0;
    int children = 0;
    vis[u] = true;
    times[u] = make_pair(++time,time);
    for (auto &x : adj[u])
    {
        if (!vis[x.first])
        {
            children++;
            parent[x.first] = u;
            APUtil(x.first, times, parent, articulationPoints);
            times[u].first  = min(times[u].first, times[x.first].first);
            if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && times[x.first].first >= times[u].second))
                articulationPoints.push_back(u);
        }
        else if (x.first != parent[u])
            times[u].first  = min(times[u].first, times[x.first].second);
    }
}

vector<int> Graph::getArticulationPoints()
{
    reset();
    vector<pair<int,int>> times (V, make_pair(0,0));
    vector<int> parent (V, -1);
    vector<int> articulationPoints;

    for (int i = 0; i < V; i++)
        if (!vis[i])
            APUtil(i, times, parent, articulationPoints);
    sort(articulationPoints.begin(), articulationPoints.end());
    return articulationPoints;
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    Graph g (n+1);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        g.dAddEdge(a, b);
    }
    vector<double> s = g.graphBFS(1);
    for (int x = 1; x <= n; x++)
    {
        if (dd[x])
        {
            printf("%.10f\n", s[x]);
        }
    }
    return 0;
}
