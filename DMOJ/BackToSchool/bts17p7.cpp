#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> spt(100005, vector<int>(17));
vector<int> he(100005);
vector<vector<int>> adj(100005);
vector<vector<long long>> diff(3, vector<long long>(100005));

void dfs(int u, int p)
{
    he[u] = he[p]+1;
    spt[u][0] = p;
    for (auto &x : adj[u])
        if (x ^ p)
            dfs(x, u);
}

void build()
{
    for (int x = 1; x < 17; x++)
        for (int y = 1; y < spt.size(); y++)
            spt[y][x] = spt[spt[y][x-1]][x-1];
}

int lca(int a, int b)
{
    if (he[a] > he[b])
        swap(a, b);
    int d = he[b]-he[a];
    for (int x = 0; x < 17; x++)
        if ((d>>x)&1)
            b = spt[b][x];
    if (a == b) return a;
    for (int x = 16; x >= 0; x--)
        if (spt[a][x] ^ spt[b][x])
            a = spt[a][x], b = spt[b][x];
    return spt[a][0];
}

long long dfs2(int u, int p, int i)
{
    for (auto &x : adj[u])
        if (x ^ p)
            diff[i][u] += dfs2(x, u, i);
    diff[i-1][u] += diff[i][u];
    return diff[i][u];
}

int main()
{
    int n, s, a, b, c;
    scanf("%i%i", &n, &s);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    build();
    while (s--)
    {
        scanf("%i%i%i", &a, &b, &c);
        int l = lca(a, b), ll = lca(l, c), la = lca(a, c), lb = lca(b, c);
        diff[2][spt[a][0]]--;
        diff[2][spt[b][0]]--;
        if (ll ^ l || (la == l && lb == l))
        {
            int add = he[l]-he[ll]+he[c]-he[ll];
            diff[1][a] += he[a]-he[l]+add;
            diff[1][b] += he[b]-he[l]+add;
            diff[1][spt[l][0]] -= add;
            diff[1][l] -= add;
            diff[2][spt[l][0]] += 2;
        }
        else
        {
            if (lb ^ l)
                swap(a, b), swap(la, lb);
            int add = he[c]-he[la];
            diff[1][a] += he[a]-he[la]+add;
            diff[1][b] += he[b]-he[l]+he[la]-he[l]+add;
            diff[1][spt[l][0]] -= he[la]-he[l]+add;
            diff[1][l] -= he[la]-he[l]+add;
            diff[2][spt[la][0]]+=2;
        }
    }
    dfs2(1, 1, 2);
    dfs2(1, 1, 1);
    for (int x = 1; x <= n; x++)
        printf("%lli ", diff[0][x]);
}
