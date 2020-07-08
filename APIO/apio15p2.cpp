#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

set<int> adj[35000];
int dist[35000];

int main()
{
    memset(dist, 0x3f, sizeof dist);
    int n, m, b, p, d, dd;
    scan(n);
    scan(m);
    for (int x = 0; x < m; x++)
    {
        scan(b);
        scan(p);
        if (!x) d = b;
        else if (x == 1) dd = b;
        adj[b].insert(p);
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> buf;
    dist[d] = 0;
    buf.push({0, d});
    while (!buf.empty())
    {
        int u = buf.top().second;
        int w = buf.top().first;
        buf.pop();
        if (w > dist[u])
            continue;
        if (u == dd)
            return 0 * printf("%i\n", dist[u]);
        for (auto &x : adj[u])
        {
            int t = u, j = 0;
            while ((t-=x) >= 0)
            {
                if (dist[u]+(++j) < dist[t])
                {
                    dist[t] = dist[u]+j;
                    buf.push({dist[t], t});
                }
                if (adj[t].find(x) != adj[t].end())
                    break;
            }
            t = u, j = 0;
            while ((t+=x) < n)
            {
                if (dist[u]+(++j) < dist[t])
                {
                    dist[t] = dist[u]+j;
                    buf.push({dist[t], t});
                }
                if (adj[t].find(x) != adj[t].end())
                    break;
            }
        }
    }
    printf("-1\n");
}
