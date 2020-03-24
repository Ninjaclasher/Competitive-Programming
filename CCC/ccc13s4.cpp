#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

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
    scan(n); scan(m);
    while(m--)
    {
        scan(a); scan(b);
        adj[a].push_back(b);
    }
    scan(a); scan(b);
    if (bfs(a,b))
        printf("yes");
    else if (bfs(b,a))
        printf("no");
    else
        printf("unknown");
    return 0;
}
