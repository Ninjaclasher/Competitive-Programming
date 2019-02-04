#include <bits/stdc++.h>

using namespace std;

template <const int MAXN>
struct Dinics
{
    struct edge
    {
        int v, flow, cap, rev;
    };
    int vis[MAXN], start[MAXN];
    vector<edge> adj[MAXN];
    bool BFS(int src, int fin)
    {
        memset(vis, -1, sizeof vis);
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

    int add_flow(int u, int flow, int fin)
    {
        if (u == fin)
            return flow;
        for (; start[u] < adj[u].size(); start[u]++)
        {
            auto &x = adj[u][start[u]];
            if (vis[x.v] == vis[u]+1 && x.flow < x.cap)
            {
                int tmp = add_flow(x.v, min(flow, x.cap-x.flow), fin);
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

    int max_flow(int src, int fin)
    {
        assert(src != fin);
        int ret = 0;
        while (BFS(src, fin))
        {
            memset(start, 0, sizeof start);
            for (int f = add_flow(src, INT_MAX, fin); f; ret += f, f = add_flow(src, INT_MAX, fin)); 
        }
        return ret;
    }

    void add_edge(int u, int v, int cap)
    {
        adj[u].push_back({v, 0, cap, adj[v].size()});
        adj[v].push_back({u, 0, 0, adj[u].size()-1});
    }
};

// 1 - 100      child
// 101 - 200    toy
// 201 - 300    category
// 301          category other
// 303          source
// 304          sink

const int CHILD = 0;
const int TOY = 100;
const int CT = 200;
const int CT_OTHER = 301;
const int SOURCE = 303;
const int SINK = 304;

int main()
{
    Dinics<350> d;
    int n, m, p;
    int k, a;
    scanf("%i%i%i", &n, &m, &p);
    const int MAXF = 10000;
    for (int x = 1; x <= n; x++)
    {
        d.add_edge(SOURCE, CHILD+x, 1);
        scanf("%i", &k);
        while (k--)
        {
            scanf("%i", &a);
            d.add_edge(CHILD+x, TOY+a, 1);
        }
    }
    vector<int> categories(m+1, CT_OTHER);
    for (int x = 1; x <= p; x++)
    {
        scanf("%i", &k);
        while (k--)
        {
            scanf("%i", &a);
            categories[a] = CT+x;
        }
        scanf("%i", &a);
        d.add_edge(CT+x, SINK, a);
    }
    d.add_edge(CT_OTHER, SINK, MAXF);
    for (int x = 1; x <= m; x++)
        d.add_edge(TOY+x, categories[x], 1);
    printf("%i\n", d.max_flow(SOURCE, SINK));
}
