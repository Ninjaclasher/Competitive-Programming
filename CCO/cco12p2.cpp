#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<pair<int,int>>>> adj(2, vector<vector<pair<int,int>>>(20005));
vector<vector<int>> dist(2, vector<int>(20005, INT_MAX));

void bfs(int s, int i)
{
    dist[i][s] = 0;
    queue<int> buf;
    buf.push(s);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[i][u])
            if (dist[i][x.first] > dist[i][u] + x.second)
                dist[i][x.first] = dist[i][u] + x.second, buf.push(x.first);
    }
}

int main() 
{
    int n, m, a, b, c, mi = INT_MAX, mii = INT_MAX;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[0][a].push_back({b, c});
        adj[1][b].push_back({a, c});
    }
    bfs(1, 0);
    bfs(n, 1);
    for (int x = 1; x <= n; x++)
    {
        for (auto &y : adj[0][x])
        {
            if (dist[0][x] == INT_MAX || dist[1][y.first] == INT_MAX) continue;
            int cur = dist[0][x] + y.second + dist[1][y.first];
            if (cur < mi)
                mii = mi, mi = cur;
            else if (cur < mii && cur > mi)
                mii = cur;
        }
    }
    printf("%i", mii == INT_MAX ? -1 : mii);
    return 0;
}
