#include <bits/stdc++.h>

using namespace std;

vector<int> par (100001), rnk(100001, 0);

int find(int n)
{
    if (n != par[n]) par[n] = find(par[n]);
    return par[n];
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (rnk[u] > rnk[v]) par[v] = u;
    else par[u] = v;
    if (rnk[u] == rnk[v]) rnk[v]++;
}

int main() 
{
    iota(par.begin(), par.end(), 0);
    int n, k, a, tt = 0;
    scanf("%i%i", &n, &k);
    vector<pair<int,pair<int,int>>> uAdj;
    for (int x = 1; x < n; x++)
    {
        scanf("%i", &a);
        uAdj.push_back(make_pair(a, make_pair(x, x+1)));
    }
    for (int x = 1; x <= n-k; x++)
        uAdj.push_back(make_pair(0, make_pair(x, x+k)));
    sort(uAdj.begin(), uAdj.end());
    for (auto &x : uAdj)
    {
        int w = x.first, u = x.second.first, v = x.second.second;
        int uu = find(u), vv = find(v);
        if (uu != vv)
        {
            tt += w;
            merge(uu, vv);
        }
    }
    printf("%i\n", tt);
    return 0;
}
