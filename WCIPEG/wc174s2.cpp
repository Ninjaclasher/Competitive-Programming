#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> adj(2, vector<vector<int>>(100001));
vector<vector<int>> dist(2, vector<int>(100001, INT_MAX));
vector<bool> vis(100001);

void bfs(int i)
{
    dist[i][1] = 0;
    queue<int> buf;
    buf.push(1);
    while (!buf.empty())
    {
        int u = buf.front(); buf.pop();
        vis[u] = false;
        for (auto &x : adj[i][u])
        {
            if (dist[i][u]+1 < dist[i][x])
            {
                dist[i][x] = dist[i][u]+1;
                if (!vis[x])
                    vis[x] = true, buf.push(x);
            }
        }
    }
}

int main()
{
    int n, m, a, b, k;
    long long cc = 0;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }
    bfs(0);
    bfs(1);
    scanf("%i", &k);
    while (k--)
    {
        scanf("%i", &a);
        if (dist[0][a] == INT_MAX || dist[1][a] == INT_MAX)
            return 0 * printf("-1\n");
        cc += dist[0][a] + dist[1][a];
    }
    printf("%lli\n", cc);
}
