#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<vector<int>> adj(MAXN);
vector<int> dist(MAXN, INT_MAX);

int main()
{
    int n, m, q, c, a, b;
    scanf("%i%i%i%i", &n, &m, &q, &c);
    assert(1 <= n && n <= 100000);
    assert(1 <= m && m <= 1000000);
    assert(1 <= q && q <= 1000000);
    assert(1 <= c && c <= n);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> buf;
    buf.push(c);
    dist[c] = 0;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (dist[x] > dist[u]+1)
                dist[x] = dist[u]+1, buf.push(x);
    }
    while (q--)
    {
        scanf("%i%i", &a, &b);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        if (dist[a] == INT_MAX || dist[b] == INT_MAX)
            printf("This is a scam!\n");
        else
            printf("%i\n", dist[a]+dist[b]);
    }
}
