#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

vector<int> suc(MAXN), cnt(MAXN), vis(MAXN), onCycle(MAXN), dist(MAXN), par(MAXN);
vector<vector<int>> adj(MAXN);

int tt = 0;
vector<int> cycle;
int mD = 0;

void fill(int u, int o, int d = 1)
{
    if (onCycle[u])
        return;
    mD = max(mD, d);
    par[u] = o;
    dist[u] = d;
    vis[u] = tt;
    for (auto &x : adj[u])
        fill(x, o, d+1);
}

bool ZERO = false;

map<int,int> cn;

long long ans = 0;

void dfs2(int u, int d = 1)
{
    cn[d] += cnt[u];
    vis[u] = tt;
    for (auto &x : adj[u])
        dfs2(x, d+1);
}

void dfs(int u, int p = 0)
{
    if (u == 0)
    {
        ZERO = true;
        dfs2(p);
        for (auto &x : cn)
            ans += (long long)x.second * (x.second-1)/2;
        return;
    }
    if (vis[u])
    {
        int v = u;
        do
        {
            cycle.push_back(v);
            onCycle[v] = cycle.size();
            for (auto &x : adj[v])
                fill(x, v);
            v = suc[v];
            dist[v] = 0;
            par[v] = v;
        }
        while (v != u);
        return;
    }
    vis[u] = tt;
    dfs(suc[u], u);
}

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &suc[x]);
        adj[suc[x]].push_back(x);
    }
    while (m--)
    {
        int a;
        scanf("%i", &a);
        cnt[a]++;
    }
    vector<int> cntt(MAXN);    
    for (int x = 1; x <= n; x++)
    {
        if (vis[x])
            continue;
        cycle.clear();
        mD = 0;
        ++tt;
        ZERO = false;
        cn.clear();
        dfs(x);
        if (ZERO)
            continue;
        for (int y = 1; y <= n; y++)
        {
            if (vis[y] == tt)
            {
                int dd = mD - dist[y];
                dd %= cycle.size();
                dd += onCycle[par[y]] - 1;
                dd %= cycle.size();
                cntt[cycle[dd]] += cnt[y];
            }
        }
    }
    for (auto &x : cntt)
        ans += x * (long long)(x-1) / 2;
    printf("%lli\n", ans);
}
