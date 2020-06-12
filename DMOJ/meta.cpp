#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<vector<int>> adj(MAXN);
vector<int> par(MAXN), par2(MAXN);
vector<char> metadiam(MAXN), metadiam2(MAXN);

int diam;

void get_diam(int u, int p, int d, int &mD, int &mN)
{
    par[u] = p;
    if (d > mD)
        mD = d, mN = u;
    for (auto &x : adj[u])
        if (x != p)
            get_diam(x, u, d + 1, mD, mN);
}

int maxDfs(int u, int p)
{
    int d = 0;
    for (auto &x : adj[u])
        if (x != p)
            d = max(d, maxDfs(x, u));
    return d + 1;
}

void dfs(int u, int d)
{
    for (auto &x : adj[u])
    {
        if (x != par[u] && x != par2[u])
        {
            int k = maxDfs(x, u);
            if (k == d)
                metadiam[u] = false;
            if (k == diam - d)
                metadiam2[u] = false;
        }
    }
    if (u != par[u])
        dfs(par[u], d + 1);
}

int main()
{
    int n, a, b;
    scanf("%i", &n);
    if (n == 1)
        return 0 * printf("1\n");
    else if (n == 2)
        return 0 * printf("2\n");
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mN1 = 0, mN2 = 0;
    get_diam(1, 1, 0, diam=0, mN1);
    get_diam(mN1, mN1, 0, diam=0, mN2);
    for (int u = mN2; par[u] != u; u = par[u])
        par2[par[u]] = u, metadiam[u] = metadiam2[u] = 1;
    metadiam[mN1] = metadiam2[mN1] = 1;
    metadiam[mN2] = metadiam2[mN1] = 0;
    // par to get path
    dfs(mN2, 0);
    for (int x = mN2; x != mN1; x = par[x])
        metadiam2[par[x]] &= metadiam2[x];
    for (int x = mN1; x != mN2; x = par2[x])
        metadiam[par2[x]] &= metadiam[x];
    int sw1 = 0, sw2 = 0;
    for (int x = mN2; x != mN1; x = par[x])
    {
        if (metadiam[par[x]])
        {
            sw1 = x;
            break;
        }
    }
    for (int x = mN1; x != mN2; x = par2[x])
    {
        if (metadiam2[par2[x]])
        {
            sw2 = x;
            break;
        }
    }
    int ans = 0;
    for (int x = 1; x <= n; x++)
        ans += metadiam[x] & metadiam2[x];
    // randomly adding different values is never sketchy
    if (ans == 0)
        ans += 1 + (sw1 != sw2);
    else
        ans += 2;
    printf("%i\n", ans);
}
