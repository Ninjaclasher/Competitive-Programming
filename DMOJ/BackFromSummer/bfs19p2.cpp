#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

vector<vector<int>> dist(MAXN, vector<int>(MAXN, INT_MAX)), grid(MAXN, vector<int>(MAXN));

int main()
{
    int n;
    scanf("%i", &n);
    char c;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf(" %c", &c);
            grid[x][y] = (c == '#');
        }
    }
    queue<pair<int,int>> buf;
    buf.push({1, 1});
    dist[1][1] = 0;
    while (!buf.empty())
    {
        int xx = buf.front().first, yy = buf.front().second;
        buf.pop();
        for (int dx = 0; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                if ((dx && dy) || (!dx && !dy))
                    continue;
                int nx = xx + dx, ny = yy + dy;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && dist[nx][ny] > dist[xx][yy] + 1 && !grid[nx][ny])
                {
                    dist[nx][ny] = dist[xx][yy] + 1;
                    buf.push({nx, ny});
                }
            }
        }
    }
    if (dist[n][n] == INT_MAX)
        return 0 * printf("-1\n");
    dist[n][n] -= 2 * (n-1);
    assert(dist[n][n] % 2 == 0);
    dist[n][n] /= 2;
    long long U = n-1;
    long long R = n-1 + dist[n][n];
    long long L = dist[n][n];
    printf("%lli\n", U * U + L * L + R * R);
}
