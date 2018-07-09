#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

vector<vector<int>> adj(200005);
vector<int> pos(200005), ans(200005);
vector<long long> bit(200010);

void update(int i, int v)
{
    for (; i < bit.size(); i+=i&-i)
        bit[i] += v;
}

long long query(int i)
{
    long long s = 0;
    for (; i > 0; i-=i&-i)
        s = (s+bit[i])%MOD;
    return s;
}

void dfs(int u)
{
    long long o = query(pos[u]);
    for (auto &x : adj[u])
        dfs(x);
    ans[u] = (query(pos[u]) - o + 1 + MOD)%MOD;
    update(pos[u], ans[u]);
}

int main()
{
    int n, a;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        adj[a].push_back(x);
    }
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        pos[a] = x;
    }
    dfs(adj[0][0]);
    for (int x = 1; x <= n; x++)
        printf("%i ", ans[x]);
}
