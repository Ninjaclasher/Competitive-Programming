#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

vector<vector<int>> adj(MAXN);
vector<vector<long long>> dist(2, vector<long long>(MAXN, LONG_MAX));

void bfs(int s, int i)
{
    dist[i][s] = 0;
    queue<int> buf;
    buf.push(s);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (dist[i][x] > dist[i][u]+1)
                dist[i][x] = dist[i][u]+1, buf.push(x);
    }
}

int main()
{
    int n, m, k, a, b, c, d;
    scanf("%i%i%i%i%i", &n, &m, &k, &a, &b);
    vector<int> kk(k);
    for (auto &x : kk)
        scanf("%i", &x);
    while (m--)
    {
        scanf("%i%i", &c, &d);
        adj[c].push_back(d);
        adj[d].push_back(c);
    }
    bfs(a, 0);
    bfs(b, 1);
    long long mi = LONG_MAX;
    for (auto &x : kk)
        mi = min(mi, dist[0][x]+dist[1][x]);
    printf("%lli\n", mi);
}
