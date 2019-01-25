#include <bits/stdc++.h>

using namespace std;

const int MAXN = 103;

vector<vector<vector<long long>>> dist(MAXN, vector<vector<long long>> (MAXN, vector<long long>(MAXN, LONG_MAX)));

vector<vector<int>> adj(MAXN, vector<int>(MAXN));

int n;

void bfs(int src)
{
    dist[1][src][src] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> buf;
    buf.push({0, src});
    while (!buf.empty())
    {
        int u = buf.top().second;
        long long w = buf.top().first;
        buf.pop();
        if (w > dist[1][src][u])
            continue;
        for (int x = 1; x <= n; x++)
            if (adj[u][x] && dist[1][src][x] > dist[1][src][u] + adj[u][x])
                dist[1][src][x] = dist[1][src][u] + adj[u][x], buf.push({dist[1][src][x], x});
    }
}

int main()
{
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            scanf("%i", &adj[x][y]);
    for (int x = 1; x <= n; x++)
        bfs(x);
    for (int d = 2; d <= n; d++)
    {
        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= n; y++)
            {
                long long &cur = dist[d][x][y];
                for (int m = 1; m <= n; m++)
                    cur = min(cur, max(dist[d-1][x][m], dist[1][m][y]));
            }
        }
    }
    int q, a, b, d;
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i%i", &a, &b, &d);
        printf("%lli\n", dist[d][a][b] == LONG_MAX ? 0 : dist[d][a][b]);
    }
}
