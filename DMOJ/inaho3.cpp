#include <bits/stdc++.h>

using namespace std;

vector<int> path(2000001);
vector<long long> dist(2000001, LONG_MAX), arr (2000001);
vector<bool> vis(2000001);
vector<int> l(10, 1), f(11, 1);
int n;

int main()
{
    int a = 0, b = 0, c;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
        scanf("%i", &l[x]);
    for (int x = 0; x < n; x++)
        f[n-x-1] = f[n-x]*l[n-x-1];
    for (int x = 0; x < f[0]; x++)
    {
        scanf("%lli", &arr[x]);
        if (arr[x] < arr[a])
            a = x;
        if (arr[x] >= arr[b])
            b = x; 
    }
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> buf;
    dist[a] = arr[a];
    buf.push(make_pair(0, a));
    while (!buf.empty())
    {
        int p = buf.top().second;
        if (p == b)
            break;
        vis[p] = false;
        buf.pop();
        for (int x = 1; x <= n; x++)
        {
            c = p+f[x];
            if (c >= 0 && p/f[x-1] == c/f[x-1] && dist[p] + arr[c] < dist[c])
            {
                path[c] = p, dist[c] = dist[p] + arr[c];
                if (!vis[c])
                    vis[c] = true, buf.push(make_pair(dist[c], c));
            }
            c = p-f[x];
            if (c >= 0 && p/f[x-1] == c/f[x-1] && dist[p] + arr[c] < dist[c])
            {
                path[c] = p, dist[c] = dist[p] + arr[c];
                if (!vis[c])
                    vis[c] = true, buf.push(make_pair(dist[c], c));
            }
        }
    }
    printf("%lli\n", dist[b]);
    for (int x = b; x != a; x = path[x])
    {
        for (int y = 1; y <= n; y++)
            printf("%i ", (x%f[y-1])/f[y]);
        printf("\n");
    }
    for (int y = 1; y <= n; y++)
        printf("%i ", (a%f[y-1])/f[y]);
    printf("\n");
}
