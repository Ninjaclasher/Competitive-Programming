#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

vector<vector<int>> adj(MAXN);

void dfs(int u, int p, int d, int &mD, int &mN)
{
    if (d > mD)
        mD = d, mN = u;
    for (auto &x : adj[u])
        if (x != p)
            dfs(x, u, d+1, mD, mN);
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
    int mD = 0, mN = 0;
    dfs(1, 1, 0, mD, mN);
    dfs(mN, mN, 0, mD=0, mN);
    printf("%i\n", mD);
}
