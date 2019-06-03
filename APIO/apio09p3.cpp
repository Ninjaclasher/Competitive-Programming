#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

vector<vector<int>> adj(MAXN), adj2(MAXN - 420000);
int coin[MAXN], mp[MAXN], coin2[MAXN], dfn[MAXN], low[MAXN], dp[MAXN];
vector<bool> vis(MAXN), pub(MAXN), pub2(MAXN);
int tt = 0, cc = 0;
stack<int> ss;

void join(int u)
{
    vis[u] = 0, mp[u] = cc;
    pub2[cc] = pub2[cc] | pub[u];
    coin2[cc] += coin[u];
}

void SCC(int u)
{
    low[u] = dfn[u] = ++tt;
    ss.push(u);
    vis[u] = 1;
    for (auto &x : adj[u])
    {
        if (dfn[x] == -1)
        {
            SCC(x);
            low[u] = min(low[u], low[x]);
        }
        else if (vis[x])
        {
            low[u] = min(low[u], dfn[x]);
        }
    }
    if (low[u] == dfn[u])
    {
        ++cc;
        while (ss.top() != u)
        {
            int v = ss.top();
            ss.pop();
            join(v);
        }
        ss.pop();
        join(u);
    }
}

int solve(int u)
{
    if (~dp[u])
        return dp[u];
    dp[u] = coin2[u];
    int ma = 0;
    for (auto &x : adj2[u])
    {
        int v = solve(x);
        if (!pub2[x])
            continue;
        pub2[u] = 1;
        ma = max(ma, v);
    }
    dp[u] += ma;
    return dp[u];
}

int main()
{
    memset(dp, -1, sizeof dp);
    memset(dfn, -1, sizeof dfn);
    memset(low, -1, sizeof low);
    int n, m, a, b, s;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
    }
    for (int x = 1; x <= n; x++)
        scanf("%i", &coin[x]);
    scanf("%i%i", &s, &a);
    while (a--)
    {
        scanf("%i", &b);
        pub[b] = 1;
    }
    for (int x = 1; x <= n; x++)
        if (dfn[x] == -1)
            SCC(x);
    for (int u = 1; u <= n; u++)
    {
        for (auto &x : adj[u])
            if (mp[u] != mp[x])
                adj2[mp[u]].push_back(mp[x]);
        adj[u].clear();
    }
    printf("%i\n", solve(mp[s]));
}
