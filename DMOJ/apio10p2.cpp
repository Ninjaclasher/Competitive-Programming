#include <bits/stdc++.h>

using namespace std;

vector<int> par(100001);
vector<vector<int>> adj(100001);
vector<map<int, int>> used(100001);

void dfs(int u, int p, int thisDiam, int &maxDiam, int &maxNode)
{
    if (thisDiam > maxDiam)
        maxDiam = thisDiam, maxNode = u;
    for (auto &x : adj[u])
        if (x != p)
            par[x] = u, dfs(x, u, thisDiam+1, maxDiam, maxNode);
}

int best (int u, int p, int &maxDiam) 
{
    int bst1 = 0, bst2 = 0;
    for (auto &x : adj[u]) 
    {
        if (x != p)
        {
            int bt = best (x, u, maxDiam) + used[u][x];
            if (bst1 <= bt)
                bst2 = bst1, bst1 = bt;
            else if (bst2 <= bt) 
                bst2 = bt;
        }
    }
    maxDiam = max(maxDiam, bst1+bst2);
    return bst1;
}

int main() 
{
    int n, k, a, b;
    scanf("%i%i", &n, &k);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mD, mD2 = 0, mN = 1, mN2 = 1;
    dfs(mN, mN, 0, mD = 0, mN);
    dfs(mN, mN, 0, mD = 0, mN2);
    if (k == 2)
    {
        for (int u = 1; u <= n; u++)
            for (auto &x : adj[u])
                used[u][x] = 1;
        for(int u = mN2; u != mN; u = par[u])
            used[u][par[u]] = used[par[u]][u] = -1;
        best(1, 1, mD2);
    }
    printf("%i", 2*(n-1)-mD+k - (k-1)*mD2);
    return 0;
}
