#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500010;

vector<int> adj(MAXN), ind(MAXN);
vector<bool> vis(MAXN);

int ans;

void dfs(int u, int mob)
{
    ans += mob;
    vis[u] = 1;
    ind[adj[u]]--;
    if (!vis[adj[u]] && (!ind[adj[u]] || mob))
        dfs(adj[u], mob^1);
}

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &adj[x]);
        ind[adj[x]]++;
    }
    for (int x = 1; x <= n; x++)
        if (!vis[x] && !ind[x])
            dfs(x, 1);
    for (int x = 1; x <= n; x++)
        if (!vis[x])
            dfs(x, 0);
    printf("%i\n", ans);
}
