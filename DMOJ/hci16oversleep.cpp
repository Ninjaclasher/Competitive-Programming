#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<vector<char>> grid(1100, vector<char>(1100, 'X'));
    vector<vector<int>> dist(1100, vector<int>(1100, INT_MAX));
    vector<vector<bool>> vis(1100, vector<bool>(1100));
    int n, m;
    pair<int,int> s, e;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            scanf(" %c", &grid[x][y]);
            if (grid[x][y] == 's')
                s = make_pair(x, y), grid[x][y] = '.';
            else if (grid[x][y] == 'e')
                e = make_pair(x, y), grid[x][y] = '.';
        }
    }
    queue<pair<int,int>> buf;
    buf.push(s);
    dist[s.first][s.second] = 0;
    while (!buf.empty())
    {
        int x = buf.front().first, y = buf.front().second;
        vis[x][y] = false;
        buf.pop();
        for (int w = 0; w < 4; w++)
        {
            int xx = 0, yy = 0;
            switch (w)
            {
                case 0: xx++; break;
                case 1: xx--; break;
                case 2: yy++; break;
                case 3: yy--; break;
            }
            if (grid[x+xx][y+yy] == '.' && dist[x+xx][y+yy] > dist[x][y]+1)
            {
                dist[x+xx][y+yy] = dist[x][y]+1;
                if (!vis[x+xx][y+yy])
                {
                    vis[x+xx][y+yy] = true;
                    buf.push(make_pair(x+xx, y+yy));
                }
            }
        }
    }
    printf("%i", dist[e.first][e.second] == INT_MAX ? -1 : dist[e.first][e.second]-1);
    return 0;
}
