#include <bits/stdc++.h>

using namespace std;

vector<int> vis(10005);
vector<vector<int>> adj(10005);

void bfs(int s)
{
    vis[s] = true;
    queue<int> buf;
    buf.push(s);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (!vis[x])
                vis[x] = true, buf.push(x);
    }
}

int main() 
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%i%i", &a, &b);
    bfs(a);
    printf("%i", vis[b]);
    return 0;
}
