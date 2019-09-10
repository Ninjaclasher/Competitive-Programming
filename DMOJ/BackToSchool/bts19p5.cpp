#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<vector<int>> adj(MAXN), ans(MAXN);
vector<bool> onDiam(MAXN);
map<int,int> segments[2][MAXN];
vector<int> par(MAXN);

void getDiam(int u, int p, int d, int &mD, int &mN)
{
    par[u] = p;
    if (d > mD)
        mD = d, mN = u;
    for (auto &x : adj[u])
        if (x != p)
            getDiam(x, u, d + 1, mD, mN);
}

pair<int,int> dfs(int u, int p, int i)
{
    int ma1 = 0, ma2 = 0, ma = 0;
    for (auto &x : adj[u])
    {
        if (x != p)
        {
            auto tmp = dfs(x, u, i);
            segments[i][u][x] = max(segments[i][u][x], tmp.second);
            ma = max(ma, tmp.second);
            if (tmp.first >= ma1)
                ma2 = ma1, ma1 = tmp.first;
            else if (tmp.first > ma2)
                ma2 = tmp.first;
        }
    }
    return {ma1 + 1, max(ma, ma1 + ma2)};
}

int main()
{
    int n, q, a, b;
    scanf("%i%i", &n, &q);
    assert(1 <= n && n <= 100000);
    assert(1 <= q && q <= 100000);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mD = -1, mN1 = 0, mN2 = 0;
    getDiam(1, 0, 0, mD, mN1);
    getDiam(mN1, 0, 0, mD=-1, mN2);
    for (int x = mN2; x; x = par[x])
        onDiam[x] = 1;
    dfs(mN1, mN1, 0);
    dfs(mN2, mN2, 1);
    for (int x = 1; x <= n; x++)
    {
        if (!onDiam[x])
            segments[0][x][0] = mD;
        else
            for (auto &y : segments[1][x])
                segments[0][x][y.first] = max(segments[0][x][y.first], y.second);
        for (auto &y : segments[0][x])
            ans[x].push_back(y.second);
        sort(ans[x].rbegin(), ans[x].rend());
    }
    while (q--)
    {
        scanf("%i%i", &a, &b);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        b--;
        printf("%i\n", b < ans[a].size() ? ans[a][b]+1 : -1);
    }
}
