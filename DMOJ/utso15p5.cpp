#include <bits/stdc++.h>

using namespace std;

vector<int> par (50001), rnk (50001), height(50001, INT_MAX);
vector<vector<int>> sparseTable(50001, vector<int> (18, 0));
vector<vector<int>> maxEdge(50001, vector<int> (18, 0));
vector<vector<pair<int,int>>> adj(50001);
vector<pair<int,pair<int,int>>> edge;
vector<pair<int,pair<int,int>>> unaddedEdge;
int minCost = 0, secondMin = INT_MAX, n;

int find (int a)
{
    if (a != par[a]) par[a] = find (par[a]);
    return par[a];
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return false;
    if (rnk[a] > rnk[b]) par[b] = a;
    else par[a] = b;
    if (rnk[a] == rnk[b]) rnk[b]++;
    return true;
}

bool MST()
{
    sort(edge.begin(), edge.end());
    int cc = 0;
    for (auto &x : edge)
    {
        int a = x.second.first, b = x.second.second, c = x.first;
        if (merge(a, b))
        {
            cc++;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
            minCost += c;
        }
        else unaddedEdge.push_back(x);
    }
    return cc == n-1;
}

void dfs(int u, int p, int w)
{
    height[u] = height[p] + 1, sparseTable[u][0] = p, maxEdge[u][0] = w;
    for (auto &x : adj[u])
        if (x.first != p) 
            dfs (x.first, u, x.second);
}

void genTable()
{
    for (int x = 1; x < sparseTable[0].size(); x++)
        for (int y = 1; y <= n; y++)
            sparseTable[y][x] = sparseTable[sparseTable[y][x-1]][x-1],
            maxEdge[y][x] = max(maxEdge[y][x-1], maxEdge[sparseTable[y][x-1]][x-1]);
}

int getLCA(int a, int b)
{
    if (height[a] > height[b])
        swap (a, b);
    int hDiff = height[b] - height[a];
    for (int x = 0; x < sparseTable[0].size(); x++)
        if ((hDiff >> x) & 1)
            b = sparseTable[b][x];
    if (a == b) return a;
    for (int x = sparseTable[0].size()-1; x >= 0; x--)
        if (sparseTable[a][x] != sparseTable[b][x])
            a = sparseTable[a][x], b = sparseTable[b][x];
    return sparseTable[a][0];
}

int maxEdgeWeight (int a, int b)
{
    int maxWeight = -1;
    if (height[a] > height[b])
        swap (a, b);
    int hDiff = height[b] - height[a];
    for (int x = 0; x < maxEdge[0].size(); x++)
        if ((hDiff >> x) & 1)
            maxWeight = max (maxWeight, maxEdge[b][x]), b = sparseTable[b][x];
    return maxWeight;
}

int getMaxEdge(int a, int b)
{
    int c = getLCA(a, b);
    return max(maxEdgeWeight(a, c), maxEdgeWeight(b, c));
}

void tryEdge()
{
    for (auto &x : unaddedEdge)
    {
        int tmp = getMaxEdge(x.second.first, x.second.second);
        if (tmp < x.first) secondMin = min (secondMin, minCost - tmp + x.first);
    }
}

int main()
{
    iota (par.begin(), par.end(), 0);
    int a, b, c, m;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        edge.push_back(make_pair(c, make_pair(a, b)));
    }
    if (!MST()) { printf("-1"); return 0; }
    height[0] = 0;
    dfs (1, 0, 0);
    genTable();
    tryEdge();
    printf("%i", secondMin == INT_MAX ? -1 : secondMin);
    return 0;
}
