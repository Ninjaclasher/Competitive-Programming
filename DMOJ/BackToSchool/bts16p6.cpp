#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c, r, m;
    long long a, b, w, ww, h, hh, n;
    pair<long long, long long> ma;
    scanf("%i%i%i", &c, &r, &m);
    vector<vector<long long>> grid(510, vector<long long> (510));
    vector<vector<pair<long long, long long>>> dist(510, vector<pair<long long, long long>> (510));
    while (m--)
    {
        scanf("%lli%lli%lli%lli%lli", &a, &b, &w, &h, &n);
        ww = w++, hh = h++;
        grid[a][b] += n;
        grid[a+ww][b] -= n*w;
        grid[a+w][b] += n*ww;
        grid[a][b+hh] -= n*h;
        grid[a][b+h] += n*hh;
        grid[a+ww][b+hh] += n*h*w;
        grid[a+w][b+hh] -= n*h*ww;
        grid[a+ww][b+h] -= n*w*hh;
        grid[a+w][b+h] += n*hh*ww;
    }
    for (int i = 0; i < 2; i++)
        for (int x = 1; x < 510; x++)
            for (int y = 1; y < 510; y++)
                grid[x][y] += grid[x-1][y] + grid[x][y-1] - grid[x-1][y-1];

    scanf("%lli%lli", &a, &b);
    queue<pair<int,int>> buf;
    buf.push(make_pair(a, b));
    dist[a][b].second = grid[a][b];
    while (!buf.empty())
    {
        int x = buf.front().first, y = buf.front().second;
        ma = max(ma, dist[x][y]);
        buf.pop();
        for (int i = 0; i < 4; i++)
        {
            int ax = 0, ay = 0;
            switch(i)
            {
                case 0: ax++; break;
                case 1: ax--; break;
                case 2: ay++; break;
                case 3: ay--; break;
            }
            pair<long long, long long> cur = make_pair(dist[x][y].first+1, dist[x][y].second + grid[x+ax][y+ay]);
            if (grid[x][y] < grid[x+ax][y+ay] && cur > dist[x+ax][y+ay])
            {
                dist[x+ax][y+ay] = cur;
                buf.push(make_pair(x+ax, y+ay));
            }
        }
    }

    printf("%lli", ma.second%1000000007);
}
