#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int l, d, a, b;
    scanf("%i%i", &l, &d);
    vector<vector<int>> aa (d+2, vector<int> (l+2, INT_MAX));
    vector<vector<int>> dist(d+2, vector<int> (l+2, INT_MAX));
    for (int y = 1; y <= d; y++)
        for (int x = 1; x <= l; x++)
            scanf("%i", &aa[y][x]);
    scanf("%i%i", &a, &b);
    queue<pair<int,int>> buf;
    buf.push(make_pair(1, 1));
    dist[1][1] = aa[1][1];
    while (!buf.empty())
    {
        int yy = buf.front().first, xx = buf.front().second;
        buf.pop();
        if (yy > d || xx > l || xx < 1) continue;
        if (dist[yy][xx] + aa[yy+1][xx] < dist[yy+1][xx])
        {
            dist[yy+1][xx] = dist[yy][xx]+aa[yy+1][xx];
            buf.push(make_pair(yy+1, xx));
        }
        if (dist[yy][xx] + aa[yy][xx+1] < dist[yy][xx+1])
        {
            dist[yy][xx+1] = dist[yy][xx]+aa[yy][xx+1];
            buf.push(make_pair(yy, xx+1));
        }
        if (dist[yy][xx] + aa[yy][xx-1] < dist[yy][xx-1])
        {
            dist[yy][xx-1] = dist[yy][xx]+aa[yy][xx-1];
            buf.push(make_pair(yy, xx-1));
        }
    }
    printf("%i\n", dist[b+1][a+1]);
    return 0;
}
