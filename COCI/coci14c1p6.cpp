#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<bool> valid, team;
vector<int> pare;

void remove(int u, int p)
{
    valid[u] = team[u];
    for (auto &x : adj[u])
    {
        if (x.first != p)
        {
            remove(x.first, u);
            valid[u] = valid[u]|valid[x.first];
        }
    }
}

void dfs(int u, int p, int diam, int &maxDiam, int &maxNode)
{
    if (diam > maxDiam)
        maxDiam = diam, maxNode = u;
    for (auto &x : adj[u])
        if (x.first != p && valid[x.first])
            dfs(x.first, u, diam+x.second, maxDiam, maxNode);
}

void bfs(int src, bool type, vector<int> &dist)
{
    queue<pair<int,int>> buf;
    buf.push(make_pair(src, src));
    while (!buf.empty())
    {
        int u = buf.front().first, p = buf.front().second;
        pare[u] = src;
        buf.pop();
        for (auto &x : adj[u])
        {
            if (x.first != p && (valid[x.first]^type))
            {
                dist[x.first] = dist[u]+x.second;
                buf.push(make_pair(x.first, u));
            }
        }
    }
}

int main()
{
    int n, k, a, b, c, max1 = 0, max2 = 0, n1, n2;
    long long t = 0;
    scanf("%i%i", &n, &k);
    adj.resize(n), team.resize(n), valid.resize(n), pare.resize(n);
    vector<int> dist(n), dis1(n), dis2(n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        a--, b--;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    for (int x = 0; x < k; x++)
    {
        scanf("%i", &a);
        team[--a] = true;
    }
    remove(a,a);
    for (int x = 0; x < n; x++)
        for (int y = 0; y < adj[x].size(); y++)
            if (valid[x] && valid[adj[x][y].first])
                t += adj[x][y].second;
    dfs(a, a, 0, max1, n1), dfs(n1, n1, 0, max2, n2);
    bfs(n1, false, dis1), bfs(n2, false, dis2);
    for (int x = 0; x < n; x++)
        if (valid[x])
            bfs(x, true, dist);

    for (int x = 0; x < n; x++)
        printf("%lli\n", dist[x] + t - max(dis1[pare[x]], dis2[pare[x]]));
    return 0;
}
