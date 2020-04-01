#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50005;
const int MINN = 1;

const int LOGN = 17;

vector<vector<pair<int,int>>> adj(MAXN);
int spt[LOGN][MAXN], max_edge[2][LOGN][MAXN];
int h[MAXN];
int par[MAXN], rnk[MAXN];
int n;

int find(int n)
{
    return par[n] == n ? n : par[n] = find(par[n]);
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        return false;
    if (rnk[a] > rnk[b])
        par[b] = a;
    else
        par[a] = b;
    if (rnk[a] == rnk[b])
        rnk[b]++;
    return true;
}

void dfs(int u, int p, int w)
{
    h[u] = h[p] + 1;
    spt[0][u] = p;
    max_edge[0][0][u] = w;
    max_edge[1][0][u] = INT_MIN;
    for (auto &x : adj[u])
        if (x.first != p)
            dfs(x.first, u, x.second);
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

void build()
{
    for (int x = 1; x < LOGN; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            spt[x][y] = spt[x-1][spt[x-1][y]];
            max_edge[0][x][y] = max(max_edge[0][x-1][y], max_edge[0][x-1][spt[x-1][y]]);
            int mi = INT_MIN;
            auto test = [&](int val){
                if (val != max_edge[0][x][y])
                    mi = max(mi, val);
            };
            test(max_edge[0][x-1][y]);
            test(max_edge[0][x-1][spt[x-1][y]]);
            test(max_edge[1][x-1][y]);                     
            test(max_edge[1][x-1][spt[x-1][y]]);
            max_edge[1][x][y] = mi;
        }
    }
}

pair<int, int> get_max(int a, int c)
{
    int d = h[a] - h[c];
    pair<int, int> ret = {INT_MIN, INT_MIN};
    for (int x = 0; x < LOGN; x++)
    {
        if (d>>x&1)
        {
            if (max_edge[0][x][a] > ret.first)
                ret.second = ret.first, ret.first = max_edge[0][x][a];
            else if (max_edge[0][x][a] < ret.first && max_edge[0][x][a] > ret.second)
                ret.second = max_edge[0][x][a];
            if (max_edge[1][x][a] > ret.second)
                ret.second = max_edge[1][x][a];
            a = spt[x][a];
        }
    }
    return ret;
}

pair<int, int> get_max_path(int a, int b)
{
    int c = lca(a, b);
    auto aa = get_max(a, c);
    auto bb = get_max(b, c);
    if (bb.first > aa.first)
        aa.second = aa.first, aa.first = bb.first;
    else if (bb.first < aa.first && bb.first > aa.second)
        aa.second = bb.first;
    if (bb.second > aa.second)
        aa.second = bb.second;
    return aa;
}

struct ed
{
    int a, b, c;
    friend bool operator<(ed &x, ed &y)
    {
        return x.c < y.c;
    }
};


int main()
{
    max_edge[0][0][0] = INT_MIN;
    max_edge[1][0][0] = INT_MIN;
    iota(par, par+MAXN, 0);
    int m;
    scanf("%i%i", &n, &m);
    vector<ed> ee(m);
    for (auto &x : ee)
        scanf("%i%i%i", &x.a, &x.b, &x.c);
    sort(ee.begin(), ee.end());
    vector<ed> alt;
    int _added = 0, cost = 0;
    for (auto &x : ee)
    {
        if (merge(x.a, x.b))
        {
            _added++;
            adj[x.a].push_back({x.b, x.c});
            adj[x.b].push_back({x.a, x.c});
            cost += x.c;
        }
        else
            alt.push_back(x);
    }
    if (_added != n-1)
        return 0 * printf("-1\n");
    dfs(1, 1, 0);
    build();
    int ans = INT_MAX;
    for (auto &x : alt)
    {
        pair<int,int> qq = get_max_path(x.a, x.b);
        if (qq.first == x.c)
        {
            if (qq.second > INT_MIN)
                ans = min(ans, cost - qq.second + x.c);
        }
        else if (qq.first > INT_MIN)
            ans = min(ans, cost - qq.first + x.c);
    }
    printf("%i\n", ans == INT_MAX ? -1 : ans);
}
