#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int v, flow, cap, rev;
};

vector<vector<edge>> adj(300);
vector<int> vis(300), start(300);

bool BFS(int src, int fin)
{
    fill(vis.begin(), vis.end(), -1);
    vis[src] = 0;
    queue<int> buf;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (vis[x.v] < 0 && x.flow < x.cap)
                vis[x.v] = vis[u]+1, buf.push(x.v);
    }
    return vis[fin] >= 0;
}

int addFlow(int u, int flow, int fin)
{
    if (u == fin)
        return flow;
    for (; start[u] < adj[u].size(); start[u]++)
    {
        auto &x = adj[u][start[u]];
        if (vis[x.v] == vis[u]+1 && x.flow < x.cap)
        {
            int tmp = addFlow(x.v, min(flow, x.cap-x.flow), fin);
            if (tmp > 0)
            {
                x.flow += tmp;
                adj[x.v][x.rev].flow -= tmp;
                return tmp;
            }
        }
    }
    return 0;
}

int maxFlow(int src, int fin)
{
    if (src == fin)
        abort();
    int ret = 0;
    while (BFS(src, fin))
    {
        fill(start.begin(), start.end(), 0);
        for (int f = addFlow(src, INT_MAX, fin); f; ret += f, f = addFlow(src, INT_MAX, fin)); 
    }
    return ret;
}

void add(int u, int v, int cap)
{
    adj[u].push_back({v, 0, cap, adj[v].size()});
    adj[v].push_back({u, 0, 0, adj[u].size()});
}

int main()
{
    int n, m, a, b;
    scanf("%i", &n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i", &a);
        add(x, 100+x, a);
    }
    scanf("%i", &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        add(a+100, b, INT_MAX);
    }
    printf("%i\n", maxFlow(1, n));
}
