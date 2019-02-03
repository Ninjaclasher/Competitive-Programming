#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MAXN = 50005, MAXH = 16;

int vi[MAXN], h[MAXN], val[MAXN], it[MAXN], vv[MAXN];

vector<long long> adj[MAXN];
int spt[MAXH][MAXN], se[MAXH][MAXN];
int cc = 0, ll = 0;

static inline void dfs(int u, int p, int w)
{
    vi[u] = 1;
    h[u] = h[p]+1;
    val[u] = val[p] + w;
    spt[0][u] = p;
    for (auto &x : adj[u])
    {
        int v = x >> 32;
        int w = x & ((1LL << 32)-1);
        if (!vi[v])
            dfs(v, u, w);
        else if ((v ^ p) && !vv[u] && !vv[v])
            vv[u] = true, it[ll++] = u;
    }
}

static inline int lca(int a, int b)
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
        if (spt[x][a] ^ spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

int dist[205][MAXN];
bool vis[MAXN];
int buf[MAXN<<3];

static inline void bfs(int src)
{
    dist[cc][src] = 0;
    int l = MAXN,r = MAXN;
    buf[r++] = src;
    while (l < r)
    {
        int u = buf[l++];
        vis[u] = false;
        for (auto &x : adj[u])
        {
            int v = x >> 32;
            int w = x & ((1LL << 32)-1);
            if (dist[cc][v] > dist[cc][u]+w)
            {
                dist[cc][v] = dist[cc][u]+w;
                if (!vis[v])
                {
                    vis[v] = true;
                    if (dist[cc][v] < dist[cc][buf[l]])
                        buf[--l] = v;
                    else
                        buf[r++] = v;
                }
            }
        }
    }
    ++cc;
}

int main()
{
    memset(dist, 0x3f, sizeof dist);
    int n, m, q, a, b, c;
    scan(n); scan(m);
    while (m--)
    {
        scan(a); scan(b); scan(c);
        adj[a].push_back((long long)b << 32 | c);
        adj[b].push_back((long long)a << 32 | c);
    }
    dfs(1, 1, 0);
    for (int x = 1; x < MAXH; x++)
        for (int y = 1; y < MAXN; y++)
            spt[x][y] = spt[x-1][spt[x-1][y]];
    for (int x = 0; x < ll; x++)
        bfs(it[x]);
    scan(q);
    while (q--)
    {
        scan(a); scan(b);
        int ans = val[a] + val[b] - (val[lca(a, b)]<<1);
        for (int x = 0; x < cc; x++)
            ans = min(ans, dist[x][a] + dist[x][b]);
        printf("%i\n", ans);
    }
}
