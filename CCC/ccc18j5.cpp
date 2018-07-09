#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(10005);

int main() 
{
    int n, m, a, mi = INT_MAX;
    bool vis = true;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &m);
        while (m--)
        {
            scanf("%i", &a);
            adj[x].push_back(a);
        }
    }
    vector<int> dist(10005, INT_MAX);
    dist[1] = 1;
    queue<int> buf;
    buf.push(1);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (dist[u]+1 < dist[x])
                dist[x] = dist[u]+1, buf.push(x);
    }
    for (int x = 1; x <= n; x++)
    {
        if (adj[x].empty()) mi = min(mi, dist[x]);
        if (dist[x] == INT_MAX) vis = false;
    }
    printf("%c\n%i", vis ? 'Y' : 'N', mi);
    return 0;
}
