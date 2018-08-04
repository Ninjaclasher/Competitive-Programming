#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

vector<vector<pair<int,int>>> adj(MAXN);

int h[MAXN];
int spt[15][MAXN], se[15][MAXN];

void dfs(int u, int p, int w)
{
    h[u] = h[p]+1;
    spt[0][u] = p;
    se[0][u] = w;
    for (auto &x : adj[u])
        if (x.first ^ p)
            dfs(x.first, u, x.second);
}

void build()
{
    for (int x = 1; x < 15; x++)
        for (int y = 0; y < MAXN; y++)
            spt[x][y] = spt[x-1][spt[x-1][y]],
            se[x][y] = se[x-1][y] + se[x-1][spt[x-1][y]];
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    int d = h[b]-h[a];
    for (int x = 14; x >= 0; x--)
        if (d>>x&1)
            b = spt[x][b];
    if (a == b)
        return a;
    for (int x = 14; x >= 0; x--)
        if (spt[x][a] ^ spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

int path(int a, int c)
{
    int d = h[a] - h[c];
    int s = 0;
    for (int x = 14; x >= 0; x--)
        if (d>>x&1)
            s += se[x][a], a = spt[x][a];
    return s;
}

int sum(int a, int b)
{
    int l = lca(a, b);
    return path(a, l) + path(b, l);
}

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        fill(adj.begin(), adj.end(), vector<pair<int,int>>());
        memset(h, 0, sizeof(h));
        memset(spt, 0, sizeof(spt));
        memset(se, 0, sizeof(se));
        int n, a, b, c, k;
        scanf("%i", &n);
        char buf[10];
        for (int x = 1; x < n; x++)
        {
            scanf("%i%i%i", &a, &b, &c);
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        dfs(1, 1, 0);
        build();
        scanf(" %s", buf);
        while (buf[1] != 'O')
        {
            scanf("%i%i", &a, &b);
            if (buf[1] == 'I')
                printf("%i\n", sum(a, b));
            else if (buf[1] == 'T')
            {
                scanf("%i", &k);
                --k;
                int l = lca(a, b);
                if (h[a]-h[l] >= k)
                {
                    for (int x = 0; x < 15; x++)
                        if (k>>x&1)
                            a = spt[x][a];
                    printf("%i\n", a);
                }
                else
                {
                    k -= h[a]-h[l];
                    k = h[b]-h[l]-k;
                    for (int x = 0; x < 15; x++)
                        if (k>>x&1)
                            b = spt[x][b];
                    printf("%i\n", b);
                }
            }
            scanf(" %s", buf);
        }
    }
}

