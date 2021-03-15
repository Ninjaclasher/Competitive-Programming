#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<set<int>> adj(MAXN);

vector<long long> ans(MAXN);

pair<long long, int> dfs(int u)
{
    pair<long long, int> ret;
    for (auto &x : adj[u])
    {
        auto v = dfs(x);
        ret.first += v.first + v.second;
        ret.second += v.second;
    }
    ret.second++;
    ret.first++;
    ans[u] = ret.first;
    return ret;
}

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 2; x <= n; x++)
    {
        int a;
        scanf("%i", &a);
        adj[a].insert(x);
    }
    dfs(1);
    for (int x = 1; x <= n; x++)
        printf("%lli%c", ans[x], x == n ? '\n' : ' ');
}
