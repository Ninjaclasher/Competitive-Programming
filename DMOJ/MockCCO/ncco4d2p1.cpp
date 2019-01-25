#include <bits/stdc++.h>

using namespace std;

struct ed
{
    long long a, b, w;
};

int main() 
{
    long long t, n, m, w, a, b, c, d;
    scanf("%lli", &t);
    while (t--)
    {
        scanf("%lli%lli%lli", &n, &m, &w);
        vector<ed> adj;
        while (m--)
        {
            scanf("%lli%lli%lli", &a, &b, &c);
            adj.push_back({a, b, c});
            adj.push_back({b, a, c});
        }
        while (w--)
        {
            scanf("%lli%lli%lli", &a, &b, &c);
            adj.push_back({a, b, -c});
        }
        vector<long long> dist(n+5, LONG_MAX);
        dist[1] = 0;
        for (int x = 1; x < n; x++)
            for (auto &y : adj)
                if (dist[y.a] != LONG_MAX && dist[y.a]+y.w < dist[y.b])
                    dist[y.b] = dist[y.a] + y.w;
        for (auto &y : adj)
        {
            if (dist[y.a] != LONG_MAX && dist[y.a]+y.w < dist[y.b])
            {
                printf("YES\n");
                goto fin;
            }
        }
        printf("NO\n");
        fin:;
    }
    return 0;
}
