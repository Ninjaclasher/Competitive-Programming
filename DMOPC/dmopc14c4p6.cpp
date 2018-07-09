#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

void dfs(int u, int p, int diam, int &maxDiam, int &maxNode)
{
    if (diam > maxDiam)
        maxDiam = diam, maxNode = u;
    for (auto &x : adj[u])
        if (x != p)
            dfs(x, u, diam+1, maxDiam, maxNode);
}

vector<int> bfs(int src)
{
    vector<int> dist (adj.size(),1);
    queue<pair<int,int>> buf;
    buf.push(make_pair(src, src));
    while (!buf.empty())
    {
        int u = buf.front().first, p = buf.front().second;
        buf.pop();
        for (auto &x : adj[u])
        {
            if (x != p)
            {
                dist[x] = dist[u]+1;
                buf.push(make_pair(x, u));
            }
        }
    }
    return dist;
}

int main()
{
    int n, a, b;
    scanf("%i", &n);
    adj.resize(n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int max1 = 0, max2 = 0, n1, n2;
    dfs(0, 0, 0, max1, n1);
    dfs(n1, n1, 0, max2, n2);
    vector<int> dis1 = bfs(n1);
    vector<int> dis2 = bfs(n2);
    for (int x = 0; x < n; x++)
        printf("%i\n", max(dis1[x], dis2[x]));
    return 0;
}
