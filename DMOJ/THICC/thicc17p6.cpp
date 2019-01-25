#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(200001);

void dfs(int u, int p, int d, int &mD, int &mN)
{
    if (d > mD)
        mD = d, mN = u;
    for (auto &x : adj[u])
        if (x.first ^ p)
            dfs(x.first, u, d+x.second, mD, mN);
}

vector<vector<int>> dist(2, vector<int>(200001));

void dfs2(int u, int p, int d, int i)
{
    dist[i][u] = dist[i][p] + d;
    for (auto &x : adj[u])
        if (x.first ^ p)
            dfs2(x.first, u, x.second, i);
}

int main()
{
    int n, t, a, b, c, d, cc = 0;
    scanf("%i%i", &n, &t);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        cc += c;
    }
    int mN = 0, mD = 0, mN2 = 0;
    dfs(1, 1, 0, mD, mN);
    dfs(mN, mN, 0, mD=0, mN2);
    dfs2(mN, 0, 0, 0);
    dfs2(mN2, 0, 0, 1);
    for (int x = 1; x <= n; x++)
        if (adj[x].size() == t)
            printf("%i %i\n", x, 2*cc-max(dist[0][x], dist[1][x]));
}
