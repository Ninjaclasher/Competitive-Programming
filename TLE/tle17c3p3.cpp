#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(300001);
vector<int> aa(300002);

int dfs(int u)
{
    int m = INT_MAX;
    for (auto &x : adj[u])
        m = min(m, dfs(x));
    return (m == INT_MAX ? 0 : m) + aa[u];
}

int main() 
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].resize(b);
        for (auto &x : adj[a])
            scanf("%i", &x);
    }
    for (int i = 1; i <= n; i++)
        scanf("%i", &aa[i]);
    printf("%i", dfs(1));
    return 0;
}
