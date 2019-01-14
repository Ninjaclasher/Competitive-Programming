#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

vector<vector<bool>> adj(MAXN, vector<bool>(MAXN));

bool bfs(int src, int fin)
{
    vector<bool> vis(MAXN);
    queue<int> buf;
    buf.push(src);
    vis[src] = true;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        if (u == fin)
            return true;
        for (int x = 1; x <= fin; x++)
            if (adj[u][x] && !vis[x])
                buf.push(x), vis[x] = true;
    }
    return false;
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    vector<pair<int,int>> ed(m);
    for (auto &x : ed)
        scanf("%i%i", &x.first, &x.second), adj[x.first][x.second] = true;
    for (auto &x : ed)
    {
        adj[x.first][x.second] = false;
        if (bfs(1, n))
            printf("YES\n");
        else
            printf("NO\n");
        adj[x.first][x.second] = true;
    }
}
