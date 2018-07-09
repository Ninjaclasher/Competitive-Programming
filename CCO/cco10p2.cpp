#include <bits/stdc++.h>

using namespace std;

int n, d;

vector<vector<int>> adj(301), sub(301, vector<int>(2));
vector<vector<long long>> dp(301, vector<long long>(700, LONG_MAX));

void dfs(int u)
{
    for (auto &x : adj[u])
    {
        dfs(x);
        sub[u][0] += sub[x][0], sub[u][1] += sub[x][1];
    }
}

long long prune(int u, int d)
{
    long long &t = dp[u][d+340];
    if (t < LONG_MAX)
        return t;
    t = INT_MAX;
    if (!d)
        return t = 0;
    else if (sub[u][1]-sub[u][0] == d) 
        return t = 1;
    else if (adj[u].size() == 2)
        for (int x = 0; x <= abs(d); x++)
            t = min(t, prune(adj[u][0], d > 0 ? x : -x) + prune(adj[u][1], d > 0 ? d-x : d+x));
    else if (adj[u].size() == 1)
        t = prune(adj[u][0], d);
    return t;
}

int main()
{
    int a, b, c, d, e;
    scanf("%i%i", &n, &d);
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        sub[a][b]++;
        while(c--)
        {
            scanf("%i", &e);
            adj[a].push_back(e);
        }
    }
    dfs(0);
    a = prune(0, sub[0][1]-sub[0][0]-d);
    printf("%i", a >= INT_MAX ? -1 : a);
}
