#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(500);
vector<int> dfn(500), low(500), ct(500), sz(500), mp(500);
vector<bool> vis(500), aa(500);
int tt = 0, cur = 0, cnt = 0;

void SCC(int u)
{
    vis[u] = true;
    dfn[u] = low[u] = ++tt;
    for (auto &x : adj[u])
    {
        if (!vis[x])
        {
            SCC(x);
            low[u] = min(low[u], low[x]);
            if (low[x] >= dfn[u])
                ct[u]++;
        }
        else
            low[u] = min(low[u], dfn[x]);
    }
}

void dfs(int u)
{
    vis[u] = true;
    sz[cur]++;
    for (auto &x : adj[u])
    {
        if (!vis[x])
        {
            if (!ct[x])
                dfs(x);
            else if (mp[x] ^ cur)
                mp[x] = cur, cnt++;
        }
    }
}

int main()
{
    int n, a, b;
    scanf("%i", &n);
    while (n)
    {
        long long ans = 0, pos = 1;
        tt = cur = cnt = 0;
        fill(vis.begin(), vis.end(), false);
        fill(aa.begin(), aa.end(), false);
        fill(dfn.begin(), dfn.end(), 0);
        fill(low.begin(), low.end(), 0);
        fill(ct.begin(), ct.end(), 0);
        fill(sz.begin(), sz.end(), 0);
        fill(mp.begin(), mp.end(), 0);
        fill(adj.begin(), adj.end(), vector<int>());
        while (n--)
        {
            scanf("%i%i", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            aa[a] = aa[b] = true;
        }
        for (int x = 1; x < 500; x++)
            if (aa[x] && !vis[x])
                SCC(x), ct[x]--;
        fill(vis.begin(), vis.end(), false);
        for (int x = 1; x < 500; x++)
        {
            if (aa[x] && !vis[x] && !ct[x])
            {
                cnt = 0;
                cur++, dfs(x);
                if (cnt == 1)
                    ans++, pos*=sz[cur];
            }
        }
        if (cur == 1)
            ans = 2, pos=(long long)sz[cur]*(sz[cur]-1)/2;
        printf("%lli %lli\n", ans, pos);
        scanf("%i", &n);
    }
}
