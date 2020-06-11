#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

vector<vector<int>> adj(MAXN, vector<int>(MAXN));

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            scanf("%i", &adj[x][y]);
    vector<int> dist(MAXN, INT_MAX);
    dist[1] = 0;
    queue<int> buf;
    buf.push(1);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (int x = 1; x <= n; x++)
            if (dist[x] > dist[u]+1 && adj[u][x])
                dist[x] = dist[u]+1, buf.push(x);
    }
    cout<<dist[n]<<endl;
}
