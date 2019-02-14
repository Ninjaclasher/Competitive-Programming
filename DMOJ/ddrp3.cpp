#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

vector<int> dist(MAXN, INT_MAX);
vector<vector<int>> adj(MAXN);

void bfs(int s)
{
    queue<int> buf;
    buf.push(s);
    dist[s] = 0;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (dist[x] > dist[u]+1)
                dist[x] = dist[u]+1, buf.push(x);
    }
}

int main()
{
    int n, m, a, b, s, t;
    scanf("%i%i", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%i%i", &s, &t);
    bfs(s);
    printf("%i\n", max(0, m - dist[t]));
}
