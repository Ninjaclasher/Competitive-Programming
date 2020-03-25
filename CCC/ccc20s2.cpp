#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

bool vis[MAXN][MAXN];
int grid[MAXN][MAXN];

vector<vector<pair<int,int>>> adj(1000005);

int main()
{
    int m, n;
    scanf("%i%i", &m, &n);
    for (int x = 1; x <= m; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf("%i", &grid[x][y]);
            adj[x * y].push_back({x, y});
        }
    }
    vis[1][1] = 1;
    queue<pair<int,int>> buf;
    buf.push({1, 1});
    while (!buf.empty())
    {
        int x = buf.front().first;
        int y = buf.front().second;
        if (x == m && y == n)
            return 0 * printf("yes\n");
        buf.pop();
        for (auto &v : adj[grid[x][y]])
        {
            int nx = v.first, ny = v.second;
            if (nx <= m && ny <= n && !vis[nx][ny])
                buf.push({nx, ny}), vis[nx][ny] = 1;
        }
    }
    printf("%s\n", vis[m][n] ? "yes" : "no");
}
