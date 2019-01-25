#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int v, flow, cap, rev;
};

vector<vector<edge>> adj(600);
vector<int> vis(600), start(600);

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

bool intersect(pair<int,int> a, pair<int,int> b)
{
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) <= 40000;
}

void add_edge(int u, int v, int cap)
{
    adj[u].push_back({v, 0, cap, adj[v].size()});
    adj[v].push_back({u, 0, 0, adj[u].size()});    
}

int main()
{
    int l, w, n;
    scanf("%i%i%i", &l, &w, &n);
    vector<pair<int,int>> aa(300);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i%i", &aa[x].first, &aa[x].second);
        add_edge(x, x+250, 1);
        for (int y = 1; y < x; y++)
        {
            if (intersect(aa[x], aa[y]))
            {
                add_edge(y+250, x, 10000000);
                add_edge(x+250, y, 10000000);
            }
        }
        if (aa[x].second <= 100)
            add_edge(n+251, x, 10000000);
        if (w-aa[x].second <= 100)
            add_edge(x+250, n+252, 10000000);
    }
    printf("%i\n", maxFlow(n+251, n+252));
}
