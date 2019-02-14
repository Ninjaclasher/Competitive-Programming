#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<int> adj(MAXN), vis(MAXN);

int cnt = 0;

void dfs(int u)
{
    if (vis[u])
    {
        printf("-1\n");
        return;
    }
    cnt++;
    vis[u] = 1;
    if (adj[u])
        dfs(adj[u]);
    else
        printf("%i\n", cnt-1);
}

int main()
{
    int n, m, p, a, b;
    scanf("%i%i%i", &n, &m, &p);
    while (n--)
    {
        scanf("%i%i", &a, &b);
        if (!adj[b])
            adj[b] = a;
    }
    dfs(p);
}
