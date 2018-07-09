#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a, b;
    scanf("%i", &n);
    vector<vector<int>> adj(10000);
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
    }
    scanf("%i%i", &a, &b);
    while (a || b)
    {
        queue<int> buf;
        buf.push(a);
        vector<int> dis(10000, INT_MAX);
        dis[a] = 0;
        while (!buf.empty())
        {
            int u = buf.front();
            buf.pop();
            for (auto &x : adj[u])
                if (dis[u]+1 < dis[x])
                    dis[x] = dis[u]+1, buf.push(x);
        }
        if (dis[b] == INT_MAX) printf("No\n");
        else printf("Yes %i\n", --dis[b]);
        scanf("%i%i", &a, &b);
    }
    return 0;
}
