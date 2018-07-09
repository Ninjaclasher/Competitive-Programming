#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, q, a, b, c;
    scanf("%i", &n);
    vector<vector<unsigned int>> dist(n, vector<unsigned int> (n, INT_MAX*(unsigned int)2));
    vector<vector<pair<int,int>>> adj(n);
    vector<bool> vis (n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
        queue<int> buf ({i});
        while (!buf.empty())
        {
            int u = buf.front();
            vis[u] = false;
            buf.pop();
            for (auto &x : adj[u])
            {
                if (dist[i][u] + x.second < dist[i][x.first])
                {
                    dist[i][x.first] = dist[i][u] + x.second;
                    if (!vis[x.first])
                    {
                        vis[x.first] = true;
                        buf.push(x.first);
                    }
                }
            }
        }
    }
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i", &a, &b);
        printf("%u\n", dist[a][b]);
    }
    return 0;
}
