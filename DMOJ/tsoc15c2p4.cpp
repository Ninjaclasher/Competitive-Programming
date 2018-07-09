#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> adj(20001);
vector<int> numPath(20001, -1);
vector<int> dist(20001, INT_MAX);
vector<pair<int,int>> dest;

int next(int u)
{
    if (numPath[u] == -1)
    {
        numPath[u] = adj[u].empty();
        for (auto &x : adj[u])
            numPath[u] += next(x);
    }
    return numPath[u];
}

void BFS(int src)
{
    queue<int> buf;
    buf.push(src);
    dist[src] = 1;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        if (adj[u].empty())
            dest.push_back(make_pair(u, dist[u]));
        for (auto &x : adj[u])
            if (dist[u]+1 < dist[x])
                dist[x] = dist[u]+1, buf.push(x);
    }
}

int main()
{
    int n, m, a, b, tt = 0;
    scanf("%i%i", &n, &m);
    vector<bool> ent (n, true);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        ent[b] = false;
    }
    for (int x = 0; x < ent.size(); x++)
        if (ent[x])
            tt += next(x), BFS(x);
    sort(dest.begin(), dest.end());
    printf("%i\n", tt);
    for (auto &x : dest)
        printf("%i ", x.second);
}
