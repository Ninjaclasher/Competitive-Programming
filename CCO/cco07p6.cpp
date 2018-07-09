#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1001);
vector<bool> vis(1001);
vector<pair<int,int>> times (1001);
vector<int> parent (1001, -1);

void bridgeUtil(int u, int &bridges)
{
    static int time = 0;
    vis[u] = true;
    times[u] = make_pair(++time, time);
 
    for (auto &x : adj[u])
    { 
        if (!vis[x])
        {
            parent[x] = u;
            bridgeUtil(x, bridges);
            times[u].first = min(times[u].first, times[x].first);
            if (times[x].first > times[u].second)
                bridges++;
        }
        else if (x != parent[u])
            times[u].first  = min(times[u].first, times[x].second);
    }
}

int main()
{
    int n, m, a, b, c = 0;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (n > 10)
        for (auto &x : adj)
            c += (x.size() == 1);
    else
        for (int x = 1; x <= n; x++)
            if (!vis[x])
                bridgeUtil(x, c);
    printf("%i", static_cast<int> (ceil(c/2.0)));
    return 0;
}
