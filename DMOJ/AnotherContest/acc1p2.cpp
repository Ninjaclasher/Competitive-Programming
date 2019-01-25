#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<vector<int>> adj(MAXN);
vector<int> par(MAXN);
vector<int> vis(MAXN);
vector<int> dist(MAXN);

int find(int n)
{
    if (n == par[n])
        return n;
    return par[n] = find(par[n]);
}

int cnt = 1;

int bfs(int a, int b)
{
    queue<pair<int,int>> buf;
    int st = cnt;
    buf.push({a, cnt});
    buf.push({b, cnt+1});
    dist[a] = dist[b] = 0;
    vis[a] = cnt, vis[b] = cnt+1;
    cnt += 2;
    while (!buf.empty())
    {
        int u = buf.front().first, t = buf.front().second;
        buf.pop();
        for (auto &x : adj[u])
        {
            if (vis[x] < st)
            {
                dist[x] = dist[u]+1;
                vis[x] = t;
                buf.push({x, t});
            }
            else if (vis[x] != t)
                return dist[u] + dist[x] + 1;
        }
    }
    abort();
}

int main()
{
    iota(par.begin(), par.end(), 0);
    int n, m, q, a, b, c;
    scanf("%i%i%i", &n, &m, &q);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        par[find(a)] = find(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while (q--)
    {
        scanf("%i%i", &a, &b);
        if (find(a) != find(b))
        {
            printf("-1\n");
            continue;
        }
        if (a == b)
            printf("0\n");
        else
            printf("%i\n", bfs(a, b));   
    }
}
