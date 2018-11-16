#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

struct e
{
    int a, b;
};

e comp(e u, e v)
{
    e ee;
    if (u.a > v.a)
        swap(u, v);
    ee.a = v.a;
    ee.b = max(u.a, v.b);
    return ee;
}

vector<vector<pair<int,int>>> adj(MAXN);
vector<vector<int>> spt(18, vector<int>(MAXN));
vector<vector<e>> edg(18, vector<e>(MAXN, e{INT_MIN, INT_MIN}));
vector<int> h(MAXN);

void dfs(int u, int p, int w)
{
    h[u] = h[p]+1;
    spt[0][u] = p;
    edg[0][u].a = w;
    edg[0][u].b = INT_MIN;
    for (auto &x : adj[u])
        if (x.first ^ p)
            dfs(x.first, u, x.second);
}

void build()
{
    for (int x = 1; x < spt.size(); x++)
    {
        for (int y = 1; y < MAXN; y++)
            spt[x][y] = spt[x-1][spt[x-1][y]],
            edg[x][y] = comp(edg[x-1][y], edg[x-1][spt[x-1][y]]);
    }
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    int d = h[b]-h[a];
    for (int x = 0; x < spt.size(); x++)
        if (d>>x&1)
            b = spt[x][b];
    if (a == b)
        return a;
    for (int x = spt.size()-1; x >= 0; x--)
        if (spt[x][a] ^ spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

e query(int a, int c)
{
    int d = h[a]-h[c];
    e ee = {INT_MIN, INT_MIN};
    for (int x = 0; x < spt.size(); x++)
        if (d>>x&1)
            ee = comp(ee, edg[x][a]), a = spt[x][a];
    return ee;
}

int quer(int a, int b)
{
    int c = lca(a, b);
    return comp(query(a, c), query(b, c)).b;
}

int main()
{
    int n, a, b, c, q;
    scanf("%i", &n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(1, 1, INT_MIN);
    build();
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i", &a, &b);
        int ans = quer(a, b);
        printf("%i\n", ans == INT_MIN ? -1 : ans);
    }
}
