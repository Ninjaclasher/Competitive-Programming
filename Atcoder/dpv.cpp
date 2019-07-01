#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int MOD;

vector<vector<int>> adj(MAXN);
vector<long long> down(MAXN, 1), up(MAXN), pre(MAXN);

long long dfs_down(int u, int p)
{
    for (auto &x : adj[u])
        if (x ^ p)
            down[u] = down[u] * (dfs_down(x, u) + 1) % MOD;
    return down[u];
}

void dfs_up(int u, int p, long long v)
{
    up[u] = v;
    long long cur = 1;
    for (auto &x : adj[u])
    {
        if (x ^ p)
        {
            pre[x] = cur % MOD;
            cur = cur * (down[x] + 1) % MOD;
        }
    }
    cur = 1;
    reverse(adj[u].begin(), adj[u].end());
    for (auto &x : adj[u])
    {
        if (x ^ p)
        {
            long long cc = (v * pre[x] % MOD * cur + 1) % MOD;
            dfs_up(x, u, cc);
            cur = cur * (down[x] + 1) % MOD;
        }
    }
}

int main()
{
    int n, a, b;
    scanf("%i%i", &n, &MOD);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_down(1, 1);
    dfs_up(1, 1, 1);
    for (int x = 1; x <= n; x++)
        printf("%lli\n", down[x] * up[x] % MOD);
}
