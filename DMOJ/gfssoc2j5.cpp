#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(500001);
vector<set<int>> adj2(500001);
vector<int> mp(500001), disc(500001, -1), low(500001, -1), ccsum(500001), mon(500001);
vector<vector<pair<int,int>>> dp(500001, vector<pair<int,int>>(2, make_pair(-1, -1)));
int tt = 0, nn = 1, n;
vector<bool> vis(500001);
stack<int> ss;

void SCC(int u)
{
    disc[u] = low[u] = ++tt;
    ss.push(u);
    vis[u] = true;
    for (auto &x : adj[u])
    {
        if (disc[x] == -1)
        {
            SCC(x);
            low[u] = min(low[u], low[x]);
        }
        else if (vis[x])
            low[u] = min(low[u], disc[x]);
    }
    if (low[u] == disc[u])
    {
        while (ss.top() != u)
        {
            int v = ss.top();
            ss.pop();
            vis[v] = false, mp[v] = nn, ccsum[nn] += mon[v];
        }
        ss.pop();
        vis[u] = false, mp[u] = nn, ccsum[nn] += mon[u];
        nn++;
    }
}

pair<int,int> dfs(int u, bool t)
{
    if (u == mp[n])
        return make_pair(t ? ccsum[u] : 0, 1);
    if (dp[u][t] != make_pair(-1, -1)) 
        return dp[u][t];
    dp[u][t] = {0, 0};
    for (auto &x : adj2[u])
    {
        for (int y = !t; y <= 1; y++)
        {
            pair<int,int> tmp = dfs(x, y);
            if (!y)
                tmp.first += ccsum[u];
            if (tmp.first > dp[u][t].first)
                dp[u][t] = tmp;
            else if (tmp.first == dp[u][t].first)
                dp[u][t].second += tmp.second, dp[u][t].second %= 1000000007;
        }
    }
    return dp[u][t];
}

int main()
{
    int m, a, b;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= n; x++)
        scanf("%i", &mon[x]);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
    }
    for (int x = 1; x <= n; x++)
        if (disc[x] == -1)
            SCC(x);
    for (int x = 1; x <= n; x++)
        for (auto &y : adj[x])
            if (mp[x] != mp[y])
                adj2[mp[x]].insert(mp[y]);
    pair<int, int> tmp = dfs(mp[1], 1);
    printf("%i %i", tmp.first, tmp.second);
}
