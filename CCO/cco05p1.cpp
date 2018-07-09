#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid(105, vector<int> (105, INT_MAX));
vector<vector<bool>> vis(105, vector<bool> (105));

bool BFS(int xx, int yy, int m, int a, int b, int c)
{
    vis[xx][yy] = true;
    queue<pair<int,int>> buf;
    buf.push({xx, yy});
    while (!buf.empty())
    {
        int x = buf.front().first, y = buf.front().second;
        buf.pop();
        for (int w = 0; w < 4; w++)
        {
            int aX = 0, aY = 0;
            switch(w)
            {
                case 0: aX++; break;
                case 1: aX--; break;
                case 2: aY++; break;
                case 3: aY--; break;
            }
            if (!vis[x+aX][y+aY] && (grid[x+aX][y+aY] == a || grid[x+aX][y+aY] == b || grid[x+aX][y+aY] == c))
            {
                if (x+aX == m) return true;
                vis[x+aX][y+aY] = true;
                buf.push({x+aX, y+aY});
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= m; x++)
        for (int y = 1; y <= n; y++)
            scanf("%i", &grid[x][y]);
    for (int x = 0; x < 10; x++)
        for (int y = 0; y < 10; y++)
            for (int z = 0; z < 10; z++, fill(vis.begin(), vis.end(), vector<bool>(105, false)))
                for (int p = 1; p <= n; p++)
                    if ((grid[1][p] == x || grid[1][p] == y || grid[1][p] == z) && BFS(1, p, m, x, y, z))
                        { printf("%i %i %i", x, y, z); return 0; }
    printf("-1 -1 -1");
    return 0;
}
