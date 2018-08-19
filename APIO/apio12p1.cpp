#include <bits/stdc++.h>

using namespace std;

struct ninja
{
    int b, c;
    long long l;
};

vector<ninja> aa (100001);
vector<int> par(100001);
vector<long long> rsum(100001);
vector<vector<int>> adj(100001);
vector<priority_queue<int>> buf(100001);
long long m, ma = 0;

void dfs(int u, int p)
{
    int uu = par[u], pp = par[p];
    buf[uu].push(aa[u].c), rsum[u] += aa[u].c;
    for (auto &x : adj[u])
        dfs(x, u);
    uu = par[u], pp = par[p];
    while (!buf[uu].empty() && rsum[u] > m)
        rsum[u] -= buf[uu].top(), buf[uu].pop();
    ma = max(ma, static_cast<long long>(buf[uu].size()*aa[u].l));
    if (u == p) return;
    rsum[p] += rsum[u];
    if (buf[uu].size() > buf[pp].size())
    {
        while (!buf[pp].empty())
            buf[uu].push(buf[pp].top()), buf[pp].pop();
        swap(par[u], par[p]);
    }
    else
        while (!buf[uu].empty())
            buf[pp].push(buf[uu].top()), buf[uu].pop();
    while (!buf[pp].empty() && rsum[p] > m)
        rsum[p] -= buf[pp].top(), buf[pp].pop();
}

int main()
{
    iota(par.begin(), par.end(), 0);
    int n, t = 0;
    scanf("%i%lli", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i%i%lli", &aa[x].b, &aa[x].c, &aa[x].l);
        adj[aa[x].b].push_back(x);
        if (!aa[x].b) t = x;
    }
    dfs(t,0);
    printf("%lli", ma);
}
