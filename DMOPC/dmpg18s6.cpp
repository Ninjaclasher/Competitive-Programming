#include <bits/stdc++.h>

using namespace std;

vector<int> low(100005), dfn(100005), par(100005), ap(100005), sz(100005);
vector<bool> vis(100005);
vector<vector<int>> adj(100005);

int t = 1, maaB = 0, maaR = INT_MAX, n;

void dfs(int u, int p)
{
    dfn[u] = low[u] = t++;
    sz[u] = 1;
    int ch = 0, maR = 1, sR = 1;
    for (auto &x : adj[u])
    {
        if (!low[x])
        {
            ch++;
            dfs(x, u);
            sz[u] += sz[x];
            low[u] = min(low[u], low[x]);
            if ((u == p && ch > 1) || (u != p && low[x] >= dfn[u]))
                ap[u] = 1, maR = max(maR, sz[x]), sR += sz[x];
        }
        else if (x ^ p)
            low[u] = min(low[u], dfn[x]);
    }
    if (ap[u])
    {
        maR = max(maR, n - sR);
        if (maR < maaR)
            maaR = maR, maaB = u;
        else if (maR == maaR)
            maaB = max(maaB, u);
    }
}

int main()
{
    int m, a, b;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int x = 1; x <= n; x++)
        if (!low[x])
            dfs(x, x);
    if (!maaB)
        printf("-1 -1\n");
    else
        printf("%i %i\n", maaB, maaR);
}
