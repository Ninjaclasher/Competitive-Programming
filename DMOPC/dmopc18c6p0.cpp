#include <bits/stdc++.h>

using namespace std;

vector<int> par(10);
vector<bool> vis(10);

bool dfs(int u)
{
    if (!u)
        return true;
    if (vis[u])
        return false;
    vis[u] = 1;
    return dfs(par[u]);
}

int main()
{
    for (int x = 1; x <= 3; x++)
        scanf("%i", &par[x]);
    for (int x = 1; x <= 3; x++)
    {
        fill(vis.begin(), vis.end(), 0);   
        if (!dfs(x))
            return 0 * printf("NO\n");
    }
    printf("YES\n");
}
