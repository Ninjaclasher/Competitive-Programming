#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500000;

vector<bool> bad(MAXN);
vector<vector<int>> adj(MAXN);
vector<int> par(MAXN);

int find(int n)
{
    if (par[n] == n)
        return n;
    return par[n] = find(par[n]);
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        return false;
    par[a] = b;
    return true;
}

int main()
{
    iota(par.begin(), par.end(), 0);
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k;
    scanf("%i", &k);
    vector<int> nd(k);
    vector<int> ans(k+1);
    for (auto &x : nd)
    {
        scanf("%i", &x);
        bad[x] = true;
    }
    int comp = n;
    for (int x = 0; x < n; x++)
        if (!bad[x])
            for (auto &y : adj[x])
                if (!bad[y])
                    comp -= merge(x, y);
    ans[k] = comp - k;
    for (int x = k-1; x >= 0; x--)
    {
        bad[nd[x]] = false;
        for (auto &y : adj[nd[x]])
            if (!bad[y])
                comp -= merge(nd[x], y);
        ans[x] = comp - x;
    }
    for (auto &x : ans)
        printf("%i\n", x);
}
