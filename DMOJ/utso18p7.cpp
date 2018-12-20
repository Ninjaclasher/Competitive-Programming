#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const long long MOD = 1000000007;

vector<vector<int>> adj(MAXN);
vector<vector<pair<int,long long>>> spt(MAXN);
vector<int> sz(MAXN);
vector<bool> vis(MAXN);
vector<long long> pop(MAXN);
struct node
{
    long long v;
    map<int,long long> ch;
};

vector<node> val(MAXN);

int dfs(int u, int p)
{
    sz[u] = 1;
    for (auto &x : adj[u])
        if (x ^ p)
            sz[u] += dfs(x, u);
    return sz[u];
}

int centroid(int u, int p, int nn)
{
    for (auto &x : adj[u])
        if (x ^ p && !vis[x] && sz[x]*2 > nn)
            return centroid(x, u, nn);
    return u;
}

int dfs2(int u, int p, int s, long long cur=1)
{
    sz[u] = 1;
    spt[u].push_back({s, cur});
    cur = (cur*pop[u])%MOD;
    for (auto &x : adj[u])
        if (x ^ p && !vis[x])
            sz[u] += dfs2(x, u, s, cur);
    return sz[u];
}

void solve(int c)
{
    c = centroid(c, c, sz[c]);
    vis[c] = true;
    for (auto &x : adj[c])
        if (!vis[x])
            dfs2(x, c, c);
    for (auto &x : adj[c])
        if (!vis[x])
            solve(x);
}

int main()
{
    int n, q, a, b, t;
    scanf("%i%i", &n, &q);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &pop[x]);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    solve(1);
    for (auto &x : spt)
        reverse(x.begin(), x.end());
    while (q--)
    {
        scanf("%i%i", &t, &a);
        if (t == 1)
        {
            scanf("%i", &b);
            val[a].v = (val[a].v + b)%MOD;
            int prev = a;
            for (auto &x : spt[a])
            {
                val[x.first].v = (val[x.first].v + x.second*b%MOD*pop[a])%MOD;
                val[x.first].ch[prev] = (val[x.first].ch[prev] + x.second*b%MOD*pop[a])%MOD;
                prev = x.first;
            }
        }
        else
        {
            long long ans = val[a].v;
            int prev = a;
            for (auto &x : spt[a])
            {
                ans += (val[x.first].v-val[x.first].ch[prev])%MOD*x.second%MOD*pop[x.first]%MOD;
                ans = (ans%MOD+MOD)%MOD;
                prev = x.first;
            }
            printf("%lli\n", ans);
        }
    }
}
