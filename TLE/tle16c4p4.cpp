#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> par, ww;

void dfs(int u, int p, long long thisDiam, int &maxNode, long long &maxDiam)
{
    par[u] = p;
    if (thisDiam > maxDiam)
        maxDiam = thisDiam, maxNode = u;
    for (auto &x : adj[u])
        if (x.first != p)
            ww[x.first] = x.second, dfs(x.first, u, thisDiam+x.second, maxNode, maxDiam);
}

int main()
{
    int n, m, q, a, b, c;
    scanf("%i%i%i", &n, &m, &q);
    adj.resize(n+1), ww.resize(n+1), par.resize(n+1, -1);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    if (q == 1)
    {
        long long mD = 0;
        int aaaa = 0;
        for (int x = 1; x <= n; x++)
        {
            if (par[x] == -1)
            {
                int mN1 = x, mN2 = x;
                long long mD1 = 0, mD2 = 0;
                dfs(x, x, 0, mN1, mD1);
                dfs(mN1, mN1, 0, mN2, mD2);
                mD+=mD2;
                aaaa++;
            }
        }
        printf("%lli", mD+aaaa-1);
    }
    else
    {
        long long rr = 0;
        for (int x = 1; x <= n; x++)
        {
            if (par[x] == -1)
            {
                int mn = x;
                long long md = 0;
                dfs(mn, mn, 0, mn, md);
                md = 0;
                dfs(mn, mn, 0, mn, md);
                long long mr = md, dist = 0;
                for (int y = mn; y != par[y]; dist += ww[y], y = par[y])
                    mr = min(mr, max(md-dist, dist));
                if (mr == rr) rr++;
                rr = max(rr, mr);
            }
        }
        printf("%lli", rr);
    }
}
