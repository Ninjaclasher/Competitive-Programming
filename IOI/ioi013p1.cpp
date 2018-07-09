#include <bits/stdc++.h>

using namespace std;

vector<int> par, dist;
vector<vector<pair<int,int>>> adj;

void dfs(int u, int p, int thisDiam, int &mDiam, int &mNode)
{
    par[u] = p;
    if (thisDiam > mDiam)
        mDiam = thisDiam, mNode = u;
    for (auto &x : adj[u])
        if (x.first != p)
            dist[x.first] = x.second, dfs(x.first, u, thisDiam+x.second, mDiam, mNode);
}

int travelTime(int N, int M, int L, int A[], int B[], int T[])
{
    int maxDiam = 0, numTree = 0;
    par.resize(N, -1);
    dist.resize(N);
    adj.resize(N);
    for (int x = 0; x < M; x++)
    {
        adj[A[x]].push_back(make_pair(B[x], T[x]));
        adj[B[x]].push_back(make_pair(A[x], T[x]));
    }
    vector<int> radius;
    for (int x = 0; x < N; x++)
    {
        if (par[x] == -1)
        {
            numTree++;
            int md, mn = x;
            dfs(mn, mn, 0, md = 0, mn);
            dfs(mn, mn, 0, md = 0, mn);
            maxDiam = max(maxDiam, md);
            int rr = md;
            for (int y = mn, cnt = 0; y != par[y]; cnt += dist[y], y = par[y])
                rr = min(rr, max(md-cnt, cnt));
            radius.push_back(rr);
        }
    }
    sort(radius.rbegin(), radius.rend());
    if (numTree > 1) maxDiam = max(maxDiam, radius[0]+radius[1]+L);
    if (numTree > 2) maxDiam = max(maxDiam, radius[1]+radius[2]+L+L);
    return maxDiam;
}
