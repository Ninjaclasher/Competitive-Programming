#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

vector<vector<int>> adj(MAXN);
vector<int> co(MAXN), par(MAXN), top(MAXN), hev(MAXN), sz(MAXN), dep(MAXN);
vector<set<pair<int,int>>> mp(MAXN);

void dfs(int u, int p)
{
    par[u] = p;
    sz[u] = 1;
    int ma = 0;
    for (auto &x : adj[u])
    {
        if (x ^ p)
        {
            dfs(x, u);
            if (sz[x] > ma)
                ma = sz[x], hev[u] = x;
            sz[u] += sz[x];
        }
    }
}

void dfs2(int u, int p, int l)
{
    top[u] = (hev[p] ^ u ? u : top[p]);
    dep[u] = l;
    if (hev[u])
        dfs2(hev[u], u, l+1);
    for (auto &x : adj[u])
        if ((x ^ p) && (x ^ hev[u]))
            dfs2(x, u, 0);
}


int main()
{
    int n, q, t, a, b;
    scanf("%i%i", &n, &q);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(1, 1, 0);
    while (q--)
    {
        scanf("%i%i", &t, &a);
        if (!t)
        {
            if (co[a])
                mp[top[a]].erase({dep[a], a});
            else
                mp[top[a]].insert({dep[a], a});
            co[a] ^= 1;
        }
        else if (t == 1)
        {
            int nd = -1;
            while (a)
            {
                if (!mp[top[a]].empty())
                {
                    int cur = mp[top[a]].begin()->second;
                    if (dep[cur] <= dep[a])
                        nd = cur;
                }
                a = par[top[a]];
            }
            printf("%i\n", nd);
        }
        else
            abort();
    }
}

