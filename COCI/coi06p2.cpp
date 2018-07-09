#include <bits/stdc++.h>

using namespace std;

int tt = 0;
vector<int> minVis(100010), firstVis(100010), lastVis(100010), height(100010);
vector<vector<int>> sparseTable(100010, vector<int>(19)), adj(100010);
map<int, pair<int,int>> cc;
vector<bool> vis(500010);

int dfs (int u, int p)
{
    height[u] = height[p]+1;
    sparseTable[u][0] = p;
    minVis[u] = firstVis[u] = ++tt;
    for (auto &x : adj[u])
    {
        if (!vis[x])
        {
            vis[x] = true;
            int v = (cc[x].first == u ? cc[x].second : cc[x].first);
            if (!firstVis[v])
                minVis[u] = min(minVis[u], dfs(v, u));
            else
                minVis[u] = min(minVis[u], firstVis[v]); 
        }
    }
    lastVis[u] = tt;
    return minVis[u];
}

inline bool cycle (int u, int v)
{
    return firstVis[u] >= firstVis[v] && lastVis[u] <= lastVis[v];
}

inline int getHigh (int a, int k)
{
    for (int x = 0; x < sparseTable[0].size(); x++)
        if ((k >> x) & 1) 
            a = sparseTable[a][x];
    return a;
}

int main() 
{
    int n, m, q, t, a, b, c, d, e;
    bool aa, bb;
    scanf("%i%i", &n, &m); 
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(x), 
        adj[b].push_back(x);
        cc[x] = make_pair(a, b);
    }
    for (int x = 1; x <= n; x++)
        if (!vis[x])
            dfs(x, 0);
    for (int x = 1; x < sparseTable[0].size(); x++)
        for (int y = 1; y <= n; y++)
            sparseTable[y][x] = sparseTable[sparseTable[y][x-1]][x-1];

    scanf("%i", &q);
    while (q--) 
    {
        scanf("%i", &t);
        if (t == 1) 
        {
            scanf("%i%i%i%i", &a, &b, &c, &d);
            if (firstVis[c] > firstVis[d]) 
                swap(c, d);
            aa = cycle(a, d), bb = cycle(b, d);
            printf("%s\n", (minVis[d] <= firstVis[c] || aa == bb) ? "yes" : "no");
        } 
        else 
        {
            scanf("%i%i%i", &a, &b, &c);
            d = getHigh(a, height[a]-height[c]-1), e = getHigh(b, height[b]-height[c]-1);
            aa = cycle(a, c), bb = cycle(b, c);
            printf("%s\n", ((!aa && !bb) || (aa && bb && (d == e || (minVis[d] < firstVis[c] && minVis[e] < firstVis[c]))) || (aa && !bb && minVis[d] < firstVis[c]) || (!aa && bb && minVis[e] < firstVis[c])) ? "yes" : "no");
        }
    }
    return 0;
}
