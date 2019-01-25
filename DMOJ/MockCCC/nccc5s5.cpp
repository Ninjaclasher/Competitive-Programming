#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int v, flow, cap, rev;
};

const int MAXN = 80100;

vector<vector<edge>> adj(MAXN);
vector<int> vis(MAXN), start(MAXN);
int n;

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
    adj[v].push_back({u, 0, 0, adj[u].size()-1});
}

inline int getPos(int x, int y)
{
    return x*n + y;
}

inline bool inbound(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}

int main()
{
    scanf("%i", &n);
    vector<vector<char>> arr(n, vector<char>(n));
    for (auto &x : arr)
        for (auto &y : x)
            scanf(" %c", &y);
    pair<int,int> dir[] = {
        {0,1},
        {0,-1},
        {1,1},
        {1,-1},
        {1,0},
        {-1,1},
        {-1,-1},
        {-1,0},
    };
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            add(40010+getPos(x, y), getPos(x, y), 1);
            char next = '\0';
            switch(arr[x][y])
            {
                case 'C': next = 'A'; 
                    add(80098, 40010+getPos(x, y), 100000);
                break;
                case 'A': next = 'L'; break;
                case 'L': next = 'I'; break;
                case 'I':
                    add(getPos(x, y), 80099, 100000);
                break;
            }
            for (auto &z : dir)
                if (inbound(x+z.first, y+z.second) && arr[x+z.first][y+z.second] == next)
                    add(getPos(x, y), 40010+getPos(x+z.first, y+z.second), 100000);
        }
    
    }
    printf("%i\n", maxFlow(80098, 80099));
}

