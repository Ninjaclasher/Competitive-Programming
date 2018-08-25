#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(105);
map<string,int> mp;
vector<int> vis(105), par(105);

int main()
{
    int n, m, c;
    cin.tie(0);
    cin.sync_with_stdio(0);
    string a, b;
    cin>>n>>m;
    mp["English"] = 0;
    for (int x = 1; x <= n; x++)
    {
        cin>>a;
        mp[a] = x;
    }
    while(m--)
    {
        cin>>a>>b>>c;
        adj[mp[a]].push_back({mp[b], c});
        adj[mp[b]].push_back({mp[a], c});
    }
    vector<int> dist(105, INT_MAX);
    dist[0] = 0;
    for (int x = 0; x <= 2*n; x++)
    {
        for (int y = 0; y <= n; y++)
            if (dist[y] != INT_MAX)
                vis[y] = 1;
        for (int y = 0; y <= n; y++)
        {
            if (vis[y])
                for (auto &v : adj[y])
                    if (!vis[v.first] && v.second < dist[v.first])
                        dist[v.first] = v.second, par[v.first] = y;
        }
    }
    long long ans = 0;
    for (int x = 0; x <= n; x++)
    {
        if (dist[x] == INT_MAX || dist[par[x]] == INT_MAX)
            return 0 * printf("Impossible\n");
        ans += dist[x];
    }
    printf("%lli\n", ans);
}

