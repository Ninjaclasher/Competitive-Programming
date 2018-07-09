#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> t(102);
    vector<vector<pair<int,int>>> adj(102);
    vector<pair<int,int>> dist(102, make_pair(INT_MAX, 0));
    int n, m, a, b, c;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        scanf("%i", &t[x]);
    scanf("%i", &m);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dist[1] = {0, t[1]};
    queue<int> buf;
    buf.push(1);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
        {
            if (dist[x.first].first > dist[u].first+x.second)
                dist[x.first] = {dist[u].first+x.second, dist[u].second+t[x.first]}, buf.push(x.first);
            else if (dist[x.first].first == dist[u].first+x.second && dist[x.first].second < dist[u].second+t[x.first])
                dist[x.first].second = dist[u].second+t[x.first], buf.push(x.first);
        }
    }
    if (dist[n].first == INT_MAX)
        return 0 * printf("impossible");
    else
        printf("%i %i", dist[n].first, dist[n].second);
    return 0;
}
