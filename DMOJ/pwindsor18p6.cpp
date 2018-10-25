#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1005);
vector<int> dist(1005, INT_MAX);

void bfs(int s)
{
    dist[s] = 0;
    queue<int> buf;
    buf.push(s);
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
    int n, m, a, b;
    scanf("%i%i%i%i", &n, &m, &a, &b);
    int c, d;
    while (m--)
    {
        scanf("%i%i", &c, &d);
        adj[c].push_back(d);
        adj[d].push_back(c);
    }
    bfs(a);
    printf("%i\n", dist[b] == INT_MAX || dist[1] == INT_MAX ? -1 : dist[b]+dist[1]);
}
