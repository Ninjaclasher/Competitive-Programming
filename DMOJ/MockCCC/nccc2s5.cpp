#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(1001);

vector<pair<int,pair<int,int>>> edg;
vector<int> par(1001), rnk(1001);

int find(int n)
{
    if (n != par[n]) return par[n] = find(par[n]);
    return par[n];
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return false;
    if (rnk[a] > rnk[b])
        par[b] = a;
    else
        par[a] = b;
    if (rnk[a] == rnk[b])
        rnk[b]++;
    return true;
}

void genMST(int n)
{
    iota(par.begin(), par.end(), 0);
    fill(rnk.begin(), rnk.end(), 0);
    for (auto &x : adj)
        x.clear();
    auto tmp = edg;
    sort(tmp.rbegin(), tmp.rend());
    int c = 0;
    for (auto &x : tmp)
    {
        if (merge(x.second.first, x.second.second))
        {
            c++;
            adj[x.second.first].push_back(make_pair(x.second.second, x.first));
            adj[x.second.second].push_back(make_pair(x.second.first, x.first));
            if (c == n-1)
                break;
        }
    }
}

int dfs(int u, int p, int w, int d)
{
    if (u == d)
        return w;
    for (auto &x : adj[u])
    {
        if (x.first != p)
        {
            int ret = dfs(x.first, u, min(w, x.second), d);
            if (~ret) return ret;
        }
    }
    return -1;
}

int main()
{
    int n, m, a, b, c, t, q;
    scanf("%i%i", &n, &m);
    while(m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        edg.push_back(make_pair(c, make_pair(a, b)));
    }
    genMST(n);
    scanf("%i", &q);
    while(q--)
    {
        scanf("%i%i%i", &t, &a, &b);
        if (t == 1)
        {
            edg[a-1].first = b;
            genMST(n);
        }
        else
        {
            scanf("%i", &c);
            printf("%i\n", dfs(a, a, INT_MAX, b) >= c);
        }
    }
}
