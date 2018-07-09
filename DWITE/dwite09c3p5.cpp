#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(10);
vector<int> colour(10);

int BFS(int src)
{
    int ma = 1;
    colour[src] = 1;
    queue<int> buf;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        vector<bool> available(5, true);
        buf.pop();
        for (auto &x : adj[u])
        {
            if (colour[x])
                available[colour[x]] = false;
            else
                buf.push(x);
        }
        for (int x = 1; x < 5; x++)
        {
            if (available[x])
            {
                colour[u] = x;
                ma = max(ma, x);
                break;
            }
            else if (x == 4)
                return INT_MAX;
        }
    }
    return ma;
}

int main()
{
    for (int qq = 0; qq < 5; qq++)
    {
        int n, a, b, ma = 1;
        scanf("%i", &n);
        fill(adj.begin(), adj.end(), vector<int>());
        fill(colour.begin(), colour.end(), 0);
        while (n--)
        {
            scanf("%i%i", &a, &b);
            if (a == b) continue;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int x = 1; x < 10; x++)
            if (!colour[x])
                ma = max(ma, BFS(x));
        printf("%i\n", ma == INT_MAX ? 0 : ma);
    }
}
