#include <bits/stdc++.h>

using namespace std;

vector<int> root;
vector<int> sz(100001, 1);
vector<char> type(100001);
vector<vector<int>> adj(100001);


pair<int,int> dfs(int u)
{
    int mi = 0, ma = 0;
    for (auto &x : adj[u])
    {
        pair<int,int> aa = dfs(x);
        mi += aa.first, ma += aa.second;
        sz[u] += sz[x];
    }
    pair<int,int> fin = make_pair(mi, ma);
    if (type[u] == 'W')
        fin = make_pair(sz[u]-ma, sz[u]-mi);
    else if (type[u] == '?')
        fin = make_pair(min(mi, sz[u]-ma), max(ma, sz[u]-mi));
    return fin;
}

int main()
{
    int n, a, mi = 0, ma = 0;
    char t, s;
    scanf("%i",  &n);
    for (int x = 1; x <= n; x++)
    {
        scanf(" %c", &t);
        if (t == 'C')
        {
            scanf(" %c", &s);
            root.push_back(x);
            type[x] = s;
            if (s != '?')
                scanf(" %c", &s);
        }
        else
        {
            scanf("%i %c", &a, &s);
            adj[a].push_back(x);
            type[x] = s;
            if (s != '?')
                scanf(" %c", &s);
        }
    }
    for (auto &x : root)
    {
        pair<int,int> aa = dfs(x);
        mi += aa.first, ma += aa.second;
    }
    printf("%i %i", mi, ma);
}
