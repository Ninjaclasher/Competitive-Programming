#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,pair<int,int>>>> adj(21);
vector<int> dist(21, INT_MAX);
vector<vector<int>> route(6);
vector<vector<vector<int>>> arrivalTime(21, vector<vector<int>> (6));

int main()
{
    int s, r, u, v, t, q = 0, a, b, c, d;
    scanf("%i%i%i%i%i", &s, &r, &u, &v, &t);
    for (int x = 1; x <= r; x++)
    {
        scanf("%i", &a);
        q+=a;
        while (a--)
        {
            scanf("%i", &b);
            route[x].push_back(b);
        }
    }
    while (q--)
    {
        scanf("%i%i%i", &a, &b, &c);
        while (c--)
        {
            scanf("%i", &d);
            arrivalTime[b][a].push_back(d);
        }
    }
    for (int x = 1; x <= r; x++)
    {
        if (!arrivalTime[route[x][0]][x].empty())
        {
            for (int y = 1; y < route[x].size(); y++)
            {
                adj[route[x][y-1]].push_back(make_pair(route[x][y], make_pair( (1440 + arrivalTime[route[x][y]][x][0] - arrivalTime[route[x][y-1]][x][0])%1440, x)));
                sort(arrivalTime[route[x][y]][x].begin(), arrivalTime[route[x][y]][x].end());
            }
        }
    }
    dist[u] = t;
    queue<int> buf;
    buf.push(u);
    while (!buf.empty())
    {
        int xx = buf.front(), dd = dist[xx]%1440;
        buf.pop();
        for (auto &x : adj[xx])
        {
            int aa = x.first, bb = x.second.first, cc = x.second.second;
            auto it = lower_bound(arrivalTime[xx][cc].begin(), arrivalTime[xx][cc].end(), dd);
            int add = *it;
            if (it == arrivalTime[xx][cc].end())
                add = arrivalTime[xx][cc][0];
            int ee = dist[xx] + bb + (1440 + add - dd)%1440;
            if (dist[aa] > ee)
            {
                dist[aa] = ee;
                buf.push(aa);
            }
        }
    }
    if (dist[v] == INT_MAX)
        printf("stay home");
    else
        printf("%i", dist[v]-t);
}
