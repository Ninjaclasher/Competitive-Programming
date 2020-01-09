#include <bits/stdc++.h>

using namespace std;

int n;

int dist[20][20][4];
pair<int,int> dir[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// 0 - top
// 1 - right
// 2 - down
// 3 - left

bool bound(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main()
{
    for (int x = 0; x < 20; x++)
        for (int y = 0; y < 20; y++)
            for (int z = 0; z < 4; z++)
                dist[x][y][z] = INT_MAX;
    int sx, sy, dx, dy;
    int r, c;
    scanf("%i", &n);
    scanf("%i%i%i%i", &sx, &sy, &dx, &dy);
    if (sx == dx && sy == dy)
        return 0 * printf("0\n");
    scanf("%i%i", &r, &c);
    if (r == sx && c == sy)
        scanf("%i%i", &r, &c);
    assert(r != sx || c != sy);
    for (int x = 0; x < 4; x++)
    {
        if (x == 0)
            dist[sx][sy][x] = abs(r - sx + 1) + abs(c - sy) + (c == sy && r > sx ? 2 : 0) + 1;
        else if (x == 1)
            dist[sx][sy][x] = abs(r - sx) + abs(c - sy - 1) + (r == sx && c < sy ? 2 : 0) + 1;
        else if (x == 2)
            dist[sx][sy][x] = abs(r - sx - 1) + abs(c - sy) + (c == sy && r < sx ? 2 : 0) + 1;
        else if (x == 3)
            dist[sx][sy][x] = abs(r - sx) + abs(c - sy + 1) + (r == sx && c > sy ? 2 : 0) + 1;
    }
    queue<pair<int,pair<int,int>>> buf;
    for (int x = 0; x < 4; x++)
    {
        if (!bound(sx + dir[x].first, sy + dir[x].second))
            dist[sx][sy][x] = INT_MAX;
        else
            buf.push({x, {sx, sy}});
    }
    while (!buf.empty())
    {
        int d = buf.front().first;
        int x = buf.front().second.first;
        int y = buf.front().second.second;
        buf.pop();
        assert(dist[x][y][d] < INT_MAX);
        for (int dd = 0; dd < 4; dd++)
        {
            int xx = x + dir[dd].first, yy = y + dir[dd].second;
            if (!bound(xx, yy))
                continue;
            int cst = 2;
            int ned = (dd + 2) % 4;
            if (abs(d - ned) % 2 == 0)
            {
                if (d == ned)
                    cst += 2;
                else
                    cst -= 2;
            }
            if (dist[x][y][d] + cst < dist[xx][yy][ned])
            {
                dist[xx][yy][ned] = dist[x][y][d] + cst + 1;
                buf.push({ned, {xx, yy}});
            }
        }
    }
    int mi = INT_MAX;
    for (int d = 0; d < 4; d++)
        mi = min(mi, dist[dx][dy][d]);
    assert(mi < INT_MAX);
    printf("%i\n", mi - 1);
}
