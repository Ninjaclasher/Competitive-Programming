#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

const int MAXN = 100005;
const int LOGN = 18;

int spt[LOGN][MAXN];
int su[LOGN][MAXN];
int h[MAXN];

vector<vector<pair<int,int>>> adj(MAXN);
int n;

void dfs(int u, int p, int w)
{
    spt[0][u] = p;
    h[u] = h[p]+1;
    su[0][u] = w;
    for (auto &x : adj[u])
        if (x.first != p)
            dfs(x.first, u, x.second);
}

void build()
{
    for (int x = 1; x < LOGN; x++)
        for (int y = 1; y <= n; y++)
            spt[x][y] = spt[x-1][spt[x-1][y]],
            su[x][y] = su[x-1][y] + su[x-1][spt[x-1][y]];
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    int d = h[b] - h[a];
    for (int x = 0; x < LOGN; x++)
        if (d>>x&1)
            b = spt[x][b];
    if (a == b)
        return a;
    for (int x = LOGN-1; x >= 0; x--)
        if (spt[x][a] != spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

int suu(int a, int c)
{
    int d = h[a] - h[c];
    int ans = 0;
    for (int x = 0; x < LOGN; x++)
        if (d>>x&1)
            ans += su[x][a], a = spt[x][a];
    return ans;
}

int dist(int a, int b)
{
    int c = lca(a, b);
    return suu(a, c) + suu(b, c);
}

long long dp[2][MAXN * 10];

int main()
{
    int d, a, b, c;
    scanf("%i%i", &n, &d);
    for (int x = 1; x < n; x++)
    {
        scan(a);
        scan(b);
        scan(c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(1, 1, 0);
    build();
    int prev[2] = {1, 1};
    long long tot = 0;
    for (int x = 1; x <= d; x++)
    {
        scan(a);
        scan(b);
        tot += dist(a, b);

        dp[0][x] = min(dp[0][x-1] + dist(a, prev[1]), dp[1][x-1] + dist(a, prev[0]));
        dp[1][x] = min(dp[0][x-1] + dist(b, prev[1]), dp[1][x-1] + dist(b, prev[0]));
        prev[0] = a;
        prev[1] = b;
    }
    printf("%lli\n", min(dp[0][d], dp[1][d]) + tot);
}
