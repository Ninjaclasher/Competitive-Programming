#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a, b;
    scanf("%i", &n);
    vector<vector<int>> adj (1005);
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
    }
    scanf("%i%i", &a, &b);
    queue<int> buf;
    vector<int> vis(1005, false);
    buf.push(a);
    while (!buf.empty())
    {
        int v = buf.front();
        vis[v] = true;
        if (v == b)
        {
            printf("Tangled");
            return 0;
        }   
        buf.pop();
        for (auto &x : adj[v])
            if (!vis[x])
                buf.push(x);
    }
    printf("Not Tangled");
    return 0;
}
