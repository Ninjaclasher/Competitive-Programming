#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(100001), sparseTable(100001, vector<int>(18));
vector<int> height(100001), first(100001, INT_MAX), sz(100001);
int n, q, c = 0;

int dfs(int u, int p)
{
    height[u] = height[p]+1;
    sparseTable[u][0] = p;
    first[u] = ++c;
    for (auto &x : adj[u]) sz[u] += dfs(x, u) + 1, ++c;
    return sz[u];
}

int getHigh(int a, int k)
{
    for (int x = 0; x < sparseTable[a].size(); x++)
        if ((k >> x) & 1) a = sparseTable[a][x];
    return a;
}

int lca(int a, int b)
{
    if (height[a] < height[b]) swap(a, b);
    a = getHigh(a, height[a] - height[b]);
    if (a == b) return a;
    for (int x = sparseTable[0].size()-1; x >= 0; x--)
        if (sparseTable[a][x] != sparseTable[b][x])
            a = sparseTable[a][x], b = sparseTable[b][x];
    return sparseTable[a][0];
}

int main()
{
    int a, b;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        while(a--)
        {
            scanf("%i", &b);
            adj[x].push_back(b);
        }
    }
    height[0] = 0;
    dfs(1, 0);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y < sparseTable[0].size(); y++)
            sparseTable[x][y] = sparseTable[sparseTable[x][y-1]][y-1];
    scanf("%i", &q);
    while(q--)
    {
        scanf("%i%i", &a, &b);
        int l = lca(a, b);
        if (first[a] < first[b])
            printf("%i\n", first[b] - first[l] - height[a] + height[l]);
        else if (first[a] > first[b])
        {
            int e = getHigh(a, height[a] - height[l] - 1);
            printf("%i\n", 2*sz[e] - height[a] + height[e] + 1 + first[b] - first[l]);
        }
        else
            printf("0\n");
    }
}
