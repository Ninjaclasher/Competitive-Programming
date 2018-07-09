#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
    DisjointSet(int V);
    bool merge(int u, int v);
    int find(int u);
private:
    int V;
    vector<int> par, rnk;
};

DisjointSet::DisjointSet(int V)
{
    this->V = V;
    rnk.resize(V+1,1);
    par.resize(V+1);
    iota(par.begin(), par.end(), 0);
}

bool DisjointSet::merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return false;
    if (rnk[u] > rnk[v])
        par[v] = u;
    else
        par[u] = v;
    if (rnk[u] == rnk[v])
        rnk[v]++;
    return true;
}

int DisjointSet::find(int u)
{
    if (u != par[u])
        par[u] = find(par[u]);
    return par[u];
}


class Tree
{
public:
    Tree(int V);
    Tree(int V, vector<pair<int,pair<int,int>>> edge, function<bool(int,int)> comp);
    inline void addEdge(int u, int v, int w = 1) 
    { 
        if (edgesAdded >= V-1)
            throw logic_error("Tree is already fully connected.");
        edgesAdded++; 
        treeSum += w;
        adj[u].push_back({v, w}), adj[v].push_back({u, w}); 
    }
    inline int getTreeSum() { return treeSum; }
    void build(function<int(int,int)> run);
    int lca(int a, int b);
    int queryPath(int a, int b);
    void longestPath(int u, int &maxPath, int &maxNode, int p, int d);
private:
    int V, edgesAdded, treeSum;
    function<int(int,int)> run;
    vector<vector<pair<int,int>>> adj;
    vector<vector<int>> spt;
    vector<vector<int>> weight;
    vector<int> height;
    void configure(int V);
    int queryPathUtil(int a, int l);
    void dfs(int u, int p, int w);
};

Tree::Tree(int V)
{
    configure(V);
}

Tree::Tree(int V, vector<pair<int,pair<int,int>>> edge, function<bool(int,int)> comp = less<int>())
{
    configure(V);
    sort(edge.begin(), edge.end(), [comp](auto &a, auto &b){return comp(a.first, b.first);});
    DisjointSet ds(V);
    for (auto &x : edge)
        if (ds.merge(x.second.first, x.second.second))
            addEdge(x.second.first, x.second.second, x.first);
}

void Tree::configure(int V)
{
    this->V = V;
    edgesAdded = treeSum = 0;
    adj.resize(V+1);
    height.resize(V+1);
    spt.resize((int)log2(V)+3, vector<int>(V+1));
    weight.resize((int)log2(V)+3, vector<int>(V+1));
}

void Tree::dfs(int u, int p, int w)
{
    height[u] = height[p]+1;
    spt[0][u] = p;
    weight[0][u] = w;
    for (auto &x : adj[u])
        if (x.first != p)
            dfs(x.first, u, x.second);
}

void Tree::build(function<int(int,int)> run = plus<int>())
{
    if (edgesAdded != V-1)
        throw logic_error("Tree is not fully connected or build function called twice.");
    edgesAdded++;
    this->run = run;
    dfs(1, 1, 0);
    for (int x = 1; x < spt.size(); x++)
        for (int y = 1; y <= V; y++)
            spt[x][y] = spt[x-1][spt[x-1][y]],
            weight[x][y] = run(weight[x-1][y], weight[x-1][spt[x-1][y]]);
}

int Tree::lca(int a, int b)
{
    int h = height[b]-height[a];
    if (h < 0)
        swap(a, b), h = -h;
    for (int x = 0; x < spt.size(); x++)
        if (h>>x & 1)
            b = spt[x][b];
    if (a == b)
        return a;
    for (int x = spt.size()-1; x >= 0; x--)
        if (spt[x][a] != spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

int Tree::queryPathUtil(int a, int l)
{
    int w = -1, h = height[a]-height[l];
    for (int x = 0; x < spt.size(); x++)
        if (h>>x & 1)
            w = (w == -1 ? weight[x][a] : run(w, weight[x][a])), a = spt[x][a];
    return w;
}

int Tree::queryPath(int a, int b)
{
    int l = lca(a, b);
    int w = queryPathUtil(a, l);
    if (l != b)
        w = (w == -1 ? queryPathUtil(b, l) : run(w, queryPathUtil(b, l)));
    return w;
}

void Tree::longestPath(int u, int &maxPath, int &maxNode, int p = -1, int d = 0)
{
    for (auto &x : adj[u])
        if (x.first != p)
            longestPath(x.first, maxPath, maxNode, u, d + x.second);
    if (d > maxPath)
        maxPath = d, maxNode = u;
}

class Graph
{
public:
    Graph(int V);
    inline void dAddEdge(int u, int v, int w = 1) { adj[u].push_back({v, w}); }
    inline void uAddEdge(int u, int v, int w = 1) { dAddEdge(u, v, w); dAddEdge(v, u, w); }
    int dijkstras(int src, int fin);
    vector<int> bfs(int src);
    set<vector<int>> getCycles(int minLength);
    vector<pair<int,int>> getBridges();
    vector<int> getArticulationPoints();
    vector<vector<int>> SCC();
private:
    int V;
    vector<vector<pair<int,int>>> adj;
    void cycleUtil(int u, int minLength, vector<bool> &vis, vector<int> &cur, set<vector<int>> &cycles);
    void bridgeUtil(int u, int &t, vector<int> &low, vector<int> &dfn, vector<int> &par, vector<pair<int,int>> &bridges);
    void APUtil(int u, int &t, vector<int> &low, vector<int> &dfn, vector<int> &par, vector<int> &articulationPoints);
    void SCCUtil(int u, int &t, int &c, vector<int> &low, vector<int> &dfn, vector<bool> &vis, vector<int> &cur, vector<vector<int>> &scc);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V+1);
}

int Graph::dijkstras(int src, int fin)
{
    vector<bool> vis(V+1);
    vector<int> dist(V+1, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>> buf;
    buf.push({0, src});
    while (!buf.empty())
    {
        int u = buf.top().second;
        buf.pop();
        vis[u] = false;
        for (auto &x : adj[u])
        {
            if (dist[u] + x.second < dist[x.first])
            {
                dist[x.first] = dist[u] + x.second;
                if (x.first == fin) return dist[x.first];
                if (!vis[x.first])
                    vis[x.first] = true, buf.push({-dist[x.first], x.first});
            }
        }
    }
    return -1;
}

vector<int> Graph::bfs(int src)
{
    vector<bool> vis(V+1);
    vector<int> dist(V+1, INT_MAX);
    dist[src] = 0;
    queue<int> buf;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        vis[u] = false;
        for (auto &x : adj[u])
        {
            if (dist[u] + x.second < dist[x.first])
            {
                dist[x.first] = dist[u] + x.second;
                if (!vis[x.first])
                    vis[x.first] = true, buf.push(x.first);
            }
        }
    }
    for (auto &x : dist)
        if (x == INT_MAX)
            x = -1;
    return dist;
}

void Graph::cycleUtil(int u, int minLength, vector<bool> &vis, vector<int> &cur, set<vector<int>> &cycles)
{
    cur.push_back(u);
    vis[u] = true;
    for (auto &x : adj[u])
    {
        if (vis[x.first])
        {
            auto it = find(cur.begin(), cur.end(), x.first);
            if (cur.end()-it >= minLength)
                cycles.insert(vector<int>(it, cur.end()));
        }
        else
            cycleUtil(x.first, minLength, vis, cur, cycles);
    }
    vis[u] = false;
    cur.pop_back();
}

set<vector<int>> Graph::getCycles(int minLength)
{
    vector<bool> vis(V+1);
    vector<int> cur(V+1);
    set<vector<int>> cycles;
    for (int x = 1; x <= V; x++)
        cycleUtil(x, minLength, vis, cur, cycles);
    return cycles;
}

void Graph::bridgeUtil(int u, int &t, vector<int> &low, vector<int> &dfn, vector<int> &par, vector<pair<int,int>> &bridges)
{
    dfn[u] = low[u] = ++t;
    for (auto &x : adj[u])
    {
        if (!low[x.first])
        {
            par[x.first] = u;
            bridgeUtil(x.first, t, low, dfn, par, bridges);
            low[u] = min(low[u], low[x.first]);
            if (low[x.first] > dfn[u])
                bridges.push_back({u, x.first});
        }
        else if (par[u] != x.first)
            low[u] = min(low[u], dfn[x.first]);
    }
}

vector<pair<int,int>> Graph::getBridges()
{
    vector<int> low(V+1), dfn(V+1), par(V+1);
    int t = 0;
    vector<pair<int,int>> bridges;
    for (int x = 1; x <= V; x++)
        if (!low[x])
            bridgeUtil(x, t, low, dfn, par, bridges);
    return bridges;
}

void Graph::APUtil(int u, int &t, vector<int> &low, vector<int> &dfn, vector<int> &par, vector<int> &articulationPoints)
{
    dfn[u] = low[u] = ++t;
    int ch = 0;
    for (auto &x : adj[u])
    {
        if (!low[x.first])
        {
            ch++;
            par[x.first] = u;
            APUtil(x.first, t, low, dfn, par, articulationPoints);
            low[u] = min(low[u], low[x.first]);
            if (!par[u] && ch > 1 || par[u] && low[x.first] >= dfn[u])
                articulationPoints.push_back(x.first);
        }
        else if (par[u] != x.first)
            low[u] = min(low[u], dfn[x.first]);
    }
}

vector<int> Graph::getArticulationPoints()
{
    vector<int> low(V+1), dfn(V+1), par(V+1);
    int t = 0;
    vector<int> articulationPoints;
    for (int x = 1; x <= V; x++)
        if (!low[x])
            APUtil(x, t, low, dfn, par, articulationPoints);
    return articulationPoints;
}

void Graph::SCCUtil(int u, int &t, int &c, vector<int> &low, vector<int> &dfn, vector<bool> &vis, vector<int> &cur, vector<vector<int>> &scc)
{
    dfn[u] = low[u] = ++t;
    cur.push_back(u);
    vis[u] = true;
    for (auto &x : adj[u])
    {
        if (!dfn[x.first])
        {
            SCCUtil(u, t, c, low, dfn, vis, cur, scc);
            low[u] = min(low[u], low[x.first]);
        }
        else if (vis[x.first])
            low[u] = min(low[u], dfn[x.first]);
    }
    if (low[u] == dfn[u])
    {
        scc.push_back(vector<int>());
        while (cur.back() != u)
            scc[c].push_back(cur.back()), vis[cur.back()] = false, cur.pop_back();
        scc[c].push_back(cur.back()), vis[cur.back()] = false, cur.pop_back();
        c++;
    }
}

vector<vector<int>> Graph::SCC()
{
    vector<int> low(V+1), dfn(V+1), par(V+1), cur;
    vector<bool> vis(V+1);
    vector<vector<int>> scc;
    int t = 0, c = 0;
    for (int x = 1; x <= V; x++)
        if (!low[x])
            SCCUtil(x, t, c, low, dfn, vis, cur, scc);
    return scc;
}

int main()
{
    /*int n, m, s = 0, a = INT_MAX;
    scanf("%i%i", &n, &m);
    Tree t(n);
    DisjointSet ds(n);
    vector<pair<int,pair<int,int>>> ed(m), unused;
    for (auto &x : ed)
        scanf("%i%i%i", &x.second.first, &x.second.second, &x.first);
    sort(ed.begin(), ed.end());
    m = 0;
    for (auto &x : ed)
    {
        if (ds.merge(x.second.first, x.second.second))
            s += x.first, t.addEdge(x.second.first, x.second.second, x.first), m = 0;
        else
            unused.push_back(x);
    }
    t.build([](int a, int b){return a > b ? a : b;});
    for (auto &x : unused)
    {
        if (x.first-t.queryPath(x.second.first, x.second.second))
            a = min(a, x.first-t.queryPath(x.second.first, x.second.second));
    }
    printf("%i", a == INT_MAX ? -1 : s+a);*/
    /*int n, m, a, b, c;
    scanf("%i%i", &n, &m);
    Graph g(n);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        g.uAddEdge(a, b, c);
    }
    vector<int> d = g.bfs(1);
    for (int x = 1; x <= n; x++)
        printf("%i\n", d[x]);
    */
    for (int tt = 0; tt < 5; tt++)
    {
        int n, m, a, b;
        scanf("%i%i", &n, &m);
        Graph g(n);
        while (m--)
        {
            scanf("%i%i", &a, &b);
            g.uAddEdge(a, b);
        }
        printf("%i\n", g.getBridges().size());
    }
}
