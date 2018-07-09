#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1000001);

bool bfs(int a, int b)
{
    vector<bool> vis(1000001);
    queue<int> buf;
    buf.push(a);
    vis[a] = true;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (!vis[x])
                buf.push(x), vis[x] = true;
    }
    return vis[b];
}

int main() 
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    while(m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
    }
    scanf("%i%i", &a, &b);
    if (bfs(a,b))
        printf("yes");
    else if (bfs(b,a))
        printf("no");
    else
        printf("unknown");
    return 0;
}
