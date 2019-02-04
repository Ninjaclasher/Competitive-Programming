#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(100001), cc(100001);
vector<int> aa(100001);
vector<long long> dist(100001, LONG_MAX);

int main()
{
    int n, c, k, a, b;
    scanf("%i%i%i", &n, &c, &k);
    for (int x = 1; x <= n; x++)
        scanf("%i", &aa[x]);

    queue<pair<int,int>> buf;
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        while (a--)
        {
            scanf("%i", &b);
            adj[b].push_back(x);
            cc[x].push_back(b);
        }
    }
    dist[1] = 0;
    for (auto &x : cc[1])
        buf.push({x, 1});
    while (!buf.empty())
    {
        int u = buf.front().first, w = buf.front().second;
        buf.pop();
        for (auto &x : adj[u])
        {
            if (dist[w]+abs(aa[w]-aa[x])+k < dist[x])
            {
                dist[x] = dist[w]+abs(aa[w]-aa[x])+k;
                for (auto y : cc[x])
                    buf.push({y, x});
            }
        }
    }
    for (int x = 1; x <= n; x++)
        printf("%lli\n", dist[x] == LONG_MAX ? -1 : dist[x]);
}
