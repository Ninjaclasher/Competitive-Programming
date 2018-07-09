#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> pho, valid;

int phoNode = 0, diameter = -1, diamNode = -1;

void dfs(int u, int p)
{
    valid[u] = pho[u];
    for (auto &x : adj[u])
    {
        if (x != p)
        {
            dfs(x, u);
            valid[u] = valid[u]|valid[x];
        }
    }
    if (valid[u]) phoNode++;
}

void diam(int u, int p, int length)
{
    if (length > diameter)
        diameter = length, diamNode = u;
    for (auto &x : adj[u])
        if (x != p && valid[x])
            diam(x, u, length+1);
}

int main()
{
    int n, m, a, b, c;
    scanf("%i%i", &n, &m);
    adj.resize(n), pho.resize(n), valid.resize(n);
    for (int x = 0; x < m; x++)
    {
        scanf("%i", &c);
        pho[c] = true;
    }
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    dfs(c, -1);
    diam(c, -1, 0);
    diam(diamNode, -1, 0);
    printf("%i\n", 2*(phoNode-1) - diameter);
    return 0;
}
