#include <bits/stdc++.h>

using namespace std;

const int MAXN = 70005, MAXH = 19;

vector<int> par(MAXN), h(MAXN), vi(MAXN);

vector<vector<pair<int,int>>> adj(MAXN);
vector<vector<int>> spt(MAXH, vector<int>(MAXN)), se(MAXH, vector<int>(MAXN));
vector<int> it;

void dfs(int u, int p, int w)
{
    vi[u] = 1;
    h[u] = h[p]+1;
    spt[0][u] = p;
    se[0][u] = w;
    for (auto &x : adj[u])
    {
        if (!vi[x.first])
            dfs(x.first, u, x.second);
        else if (x.first ^ p)
            it.push_back(u), it.push_back(x.first);
    }
    
}

void build()
{
    for (int x = 1; x < MAXH; x++)
        for (int y = 1; y < MAXN; y++)
            spt[x][y] = spt[x-1][spt[x-1][y]],
            se[x][y] = se[x-1][y] + se[x-1][spt[x-1][y]];
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    int d = h[b]-h[a];
    for (int x = 0; x < MAXH; x++)
        if (d>>x&1)
            b = spt[x][b];
    if (a == b)
        return a;
    for (int x = MAXH-1; x >= 0; x--)
        if (spt[x][a] != spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

int edd(int a, int c)
{
    int d = h[a]-h[c], sum = 0;
    for (int x = 0; x < MAXH; x++)
        if (d>>x&1)
            sum += se[x][a], a = spt[x][a];
    return sum;
}

int edge_sum(int a, int b)
{
    int c = lca(a, b);
    return edd(a, c) + edd(b, c);
}

vector<vector<int>> dist(205, vector<int>(MAXN, INT_MAX));
bool vis[MAXN];
int buf[MAXN<<7];

int cc = 0;
void bfs(int src)
{
    dist[cc][src] = 0;
    int l = 0,r = 0;
    buf[r++] = src;
    while (l < r)
    {
        int u = buf[l++];
        vis[u] = false;
        for (auto &x : adj[u])
        {
            if (dist[cc][x.first] > dist[cc][u]+x.second)
            {
                dist[cc][x.first] = dist[cc][u]+x.second;
                if (!vis[x.first])
                    vis[x.first] = true, buf[r++] = x.first;
            }
        }
    }
    ++cc;
}

int main()
{
    iota(par.begin(), par.end(), 0);
    int n, m, q, a, b, c;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(1, 1, 0);
    build();
    sort(it.begin(), it.end());
    it.erase(unique(it.begin(), it.end()), it.end());
    for (auto &x : it)
        bfs(x);
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i", &a, &b);
        int ans = edge_sum(a, b);
        for (int x = 0; x < cc; x++)
            ans = min(ans, dist[x][a] + dist[x][b]);
        printf("%i\n", ans);
    }
}
