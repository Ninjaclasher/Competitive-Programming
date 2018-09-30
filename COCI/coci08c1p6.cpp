#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300100;

vector<vector<int>> adj(MAXN);
vector<int> par(MAXN, -1);

void dfs(int u, int p, int d, int &mD, int &mN)
{
    par[u] = p;
    if (d >= mD)
        mD = d, mN = u;
    for (auto &x : adj[u])
        if (x ^ p)
            dfs(x, u, d+1, mD, mN);
}

pair<int,int> getCenter(int u)
{
    int mD = 0, mN = 0;
    dfs(u, u, 0, mD, mN);
    dfs(mN, mN, 0, mD=0, mN);
    int rr = mD, nd = mN;
    for (int y = mN, cnt = 0; y != par[y]; cnt++, y = par[y])
        if (rr > max(mD-cnt, cnt))
            rr = max(mD-cnt, cnt), nd = y;
    return make_pair(nd, mD);
}

vector<pair<int,int>> ed;

void run_brute()
{
    pair<int,int> ans, ne;
    int minD = INT_MAX;
    for (auto &x : ed)
    {
        int a = x.first, b = x.second;
        adj[a].erase(find(adj[a].begin(), adj[a].end(), b));
        adj[b].erase(find(adj[b].begin(), adj[b].end(), a));
        pair<int,int> aa = getCenter(a);
        pair<int,int> bb = getCenter(b);
        int dd = max(aa.second, max(bb.second, (int)(1 + ceil(aa.second/2.0) + ceil(bb.second/2.0))));
        if (dd < minD)
        {
            minD = dd;
            ans = {a, b};
            ne = {aa.first, bb.first};
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%i\n", minD);
    printf("%i %i\n", ans.first, ans.second);
    printf("%i %i\n", ne.first, ne.second);
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
        ed.push_back({a, b});
    }
    int mD = 0, mN = 0;
    dfs(1, 1, 0, mD, mN);
    dfs(mN, mN, 0, mD=0, mN);
    int rr = mD, nd = mN;
    for (int y = mN, cnt = 0; y != par[y]; cnt++, y = par[y])
    {
        if (rr > max(mD-cnt-1, cnt))
            rr = max(mD-cnt-1, cnt), nd = y;
    }
    if (n <= 3000)
    {
        run_brute();
        return 0;
    }
    pair<int,int> ans = {par[nd], nd};
    adj[nd].erase(find(adj[nd].begin(), adj[nd].end(), par[nd]));
    adj[par[nd]].erase(find(adj[par[nd]].begin(), adj[par[nd]].end(), nd));
    
    pair<int,int> aa = getCenter(ans.first);
    pair<int,int> bb = getCenter(ans.second);
    printf("%i\n", max(aa.second, max(bb.second, (int)(ceil(aa.second/2.0)+ceil(bb.second/2.0)+1))));
    printf("%i %i\n", ans.first, ans.second);
    printf("%i %i\n", aa.first, bb.first);
}
