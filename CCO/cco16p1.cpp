#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
int cut = 0, student = 0;

void BFS(int src, int k)
{
    queue<pair<int,int>> buf;
    buf.push(make_pair(src, 0));
    int nNode = 0, cycle = 0;
    vis[src] = true;
    while (!buf.empty())
    {
        int u = buf.front().first, p = buf.front().second;
        buf.pop();
        nNode++;
        for (auto &x : adj[u])
        {
            if (x != p)
            {
                if (vis[x]) cycle = true;
                else buf.push(make_pair(x, u));
                vis[x] = true;
            }
        }
    }
    if (nNode >= k)
    {
        student += nNode-nNode%k, cut += nNode/k;
        if (!(nNode%k)) cut--;
        if (cycle && nNode > k) cut++;
    }
}

int main()
{
    int n, m, k, a, b;
    scanf("%i%i%i", &n, &m, &k);
    adj.resize(n+1);
    vis.resize(n+1);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int x = 1; x <= n; x++)
        if (!vis[x])
            BFS(x, k);
    printf("%i %i\n", student, cut);
}
