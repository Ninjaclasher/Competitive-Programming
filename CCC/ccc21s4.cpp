#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<vector<int>> adj(MAXN);
vector<int> dist(MAXN, INT_MAX / 2);
vector<int> pos(MAXN), s(MAXN), cur_dists(MAXN);

int main()
{
    int n, w, d;
    scanf("%i%i%i", &n, &w, &d);
    while (w--)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        adj[b].push_back(a);
    }
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &s[x]);
        pos[s[x]] = x;
    }
    queue<int> buf;
    buf.push(n);
    dist[n] = 0;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (dist[x] > dist[u] + 1)
                dist[x] = dist[u] + 1, buf.push(x);
    }
    multiset<int> dists;
    for (int x = 1; x <= n; x++)
    {
        cur_dists[x] = pos[x] - 1 + dist[x];
        dists.insert(cur_dists[x]);
    }
    while (d--)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        int _a = a, _b = b;
        a = s[a];
        b = s[b];
        dists.erase(dists.find(cur_dists[a]));
        dists.erase(dists.find(cur_dists[b]));
        swap(pos[a], pos[b]);
        swap(s[_a], s[_b]);
        cur_dists[a] = pos[a] - 1 + dist[a];
        cur_dists[b] = pos[b] - 1 + dist[b];
        dists.insert(cur_dists[a]);
        dists.insert(cur_dists[b]);
        printf("%i\n", min(*dists.begin(), pos[n] - 1));
    }
}
