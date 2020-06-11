#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<vector<int>> adj(MAXN);
vector<char> valid(MAXN);
vector<char> gym(MAXN);

long long ans = 0;
int f;
bool FF = false, GG = false;
int FW;

bool dfs(int u, int p)
{
    valid[u] = gym[u];
    for (auto &x : adj[u])
        if (x != p)
            valid[u] |= dfs(x, u);
    if (valid[u])
        ans++;
    return valid[u];
}

int closestGym, dd = 0;

void dfs5(int u, int p, int d, int &mD, int &mN)
{
    if (d > mD)
        mD = d, mN = u;
    for (auto &x : adj[u])
        if (x != p && valid[x])
            dfs5(x, u, d+1, mD, mN);
}

int dfs2(int u, int p, int w)
{
    if (u == 1)
        return w;
    for (auto &x : adj[u])
        if (x != p)
        {
            int r = dfs2(x, u, w+1);
            if (r)
                return r;
        }
    return 0;
}

void dfs3(int u, int p, int w)
{
    if (valid[u])
    {
        closestGym = u;
        dd = w;
        return;
    }
    for (auto &x : adj[u])
    {
        if (x != p)
            dfs3(x, u, w+1);
        if (closestGym)
            return;
    }
}

int dfs4(int u, int p)
{
    if (!valid[u])
        return 0;
    int ma = 0;
    for (auto &x : adj[u])
        if (x != p)
            ma = max(ma, dfs4(x, u) + 1);
    return ma;
}

int main()
{
    int n, k, a, b, c;
    scanf("%i%i%i", &n, &k, &f);
    while (k--)
    {
        scanf("%i", &c);
        gym[c] = true;
    }
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    ans--;
    int mD = 0, mN = 0;
    dfs5(1, 1, 0, mD, mN);
    dfs3(f, f, 0);
    long long ret = 2*ans - mD;
    ret = min(ret, ans + dd);
    printf("%lli\n", ret);
}
