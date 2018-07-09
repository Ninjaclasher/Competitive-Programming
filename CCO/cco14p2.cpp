#include <bits/stdc++.h>

using namespace std;

struct ed
{
    int a, b, w, c;
};

vector<vector<int>> dist(2, vector<int>(100005, 1<<30));
vector<bool> vis(100005);
vector<pair<int,int>> adj[2][100005];
vector<ed> edg;

void bfs(int s, int i)
{
    queue<int> buf;
    buf.push(s);
    dist[i][s] = 0;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        vis[u] = false;
        for (auto &x : adj[i][u])
        {
            if (dist[i][x.first] > dist[i][u]+x.second)
            {
                dist[i][x.first] = dist[i][u]+x.second;
                if (!vis[x.first])
                    vis[x.first] = true, buf.push(x.first);
            }
        }
    }
}

int main() 
{
    int n, m, q, a, b, c, d, e, f;
    scanf("%i%i%i%i", &n, &m, &e, &f);
    while (m--)
    {
        scanf("%i%i%i%i", &a, &b, &c, &d);
        adj[0][a].push_back({b, c});
        adj[1][b].push_back({a, c});
        edg.push_back({a, b, c, d});
    }
    bfs(e,0); bfs(f, 1);
    vector<pair<int,int>> aa;
    for (auto &x : edg)
        aa.push_back({dist[0][x.a] + x.w + dist[1][x.b], x.c});
    sort(aa.begin(), aa.end());
    vector<int> aaa(aa.size());
    aaa[0] = aa[0].second;
    for (int x = 1; x < aa.size(); x++)
        aaa[x] = aaa[x-1] + aa[x].second;
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i", &d);
        auto it = upper_bound(aa.begin(), aa.end(), make_pair(d, INT_MAX));
        printf("%lli\n", it == aa.begin() ? 0 : aaa[(--it)-aa.begin()]);
    }
    return 0;
}
