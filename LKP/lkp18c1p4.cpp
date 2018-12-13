#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

struct ed
{
    int b, i;
    long long c;
};

vector<vector<ed>> adj(MAXN);
vector<long long> dist(MAXN);

bool solve(int a, int b, long long c, long long k)
{
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[a] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> buf;
    buf.push({0, a});
    while (!buf.empty())
    {
        int u = buf.top().second;
        long long w = buf.top().first;
        buf.pop();
        if (dist[u] < w)
            continue;
        if (u == b)
            return w < c;
        for (auto &x : adj[u])
            if (dist[u] + x.c < dist[x.b] && x.i <= k)
                dist[x.b] = dist[u]+x.c, buf.push({dist[x.b], x.b});
    }
    return false;
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    long long c;
    for (int x = 1; x <= m; x++)
    {
        scanf("%i%i%lli", &a, &b, &c);
        adj[a].push_back({b, x, c});
        adj[b].push_back({a, x, c});
    }
    scanf("%i%i%lli", &a, &b, &c);
    if (a == b)
        return 0 * printf("0\n");
    long long l = 1, r = 300000;
    while (l <= r)
    {
        int mid = l+r>>1;
        if (solve(a, b, c, mid))
            r = mid-1;
        else
            l = mid+1;
    }
    if (r == 300000)
        return 0 * printf("-1\n");
    cout<<r+1<<endl;
}

