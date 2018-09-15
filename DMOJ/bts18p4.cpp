#include <bits/stdc++.h>

using namespace std;

static inline __attribute__((always_inline)) bool valid(long long y)
{
    long double val = sqrt(1+4*y);
    if (abs((long long)val-val) <= 1e-10)
        return ((long long)val)&1;
    return false;
}

const int MAXN = 100010;

vector<bool> val(MAXN), vis(MAXN);
vector<vector<int>> adj(MAXN);

void dfs(int u, int p, int d, int &mD, int &mN)
{
    vis[u] = true;
    if (d > mD)
        mD = d, mN = u;
    for (auto &x : adj[u])
        if ((x ^ p) && val[x])
            dfs(x, u, d+1, mD, mN);
}

int main()
{
    int n, a, b, ma = 0;
    long long y;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%lli", &y);
        val[x] = valid(y);
    }
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int x = 1; x <= n; x++)
    {
        if (!vis[x] && val[x])
        {
            int mD = 0, mN = 0;
            dfs(x, x, 1, mD, mN);
            dfs(mN, mN, 1, mD=0, mN);
            ma = max(ma, mD);
        }
    }
    printf("%i\n", ma);
}

