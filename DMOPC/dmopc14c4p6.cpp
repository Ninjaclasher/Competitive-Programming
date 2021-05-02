#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(500005);
vector<vector<int>> dis(2, vector<int>(500005));

void dfs(int u, int p, int d, int &mN, int &mD, int c)
{
    if (d > mD)
        mD = d, mN = u;
    for (auto &x : adj[u])
        if (x != p)
            dfs(x, u, d+1, mN, mD, c);
    dis[c][u] = d;
}

int main() 
{
    int n, a, b;
    scanf("%i", &n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mN = 0, mD = 0;
    dfs(1, 1, 0, mN, mD, 0);
    dfs(mN, mN, 1, mN, mD=0, 0);
    dfs(mN, mN, 1, mN, mD=0, 1);
    for (int x = 1; x <= n; x++)
        printf("%i\n", max(dis[0][x], dis[1][x]));
    return 0;
}
