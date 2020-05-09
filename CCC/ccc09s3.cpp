#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> adj (50, vector<bool>(50, false));

void BFS(int a, int b)
{
    vector<int> dist (50, INT_MAX);
    vector<bool> vis (50, false);
    queue<int> buf;
    buf.push(a);
    dist[a] = 0;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        vis[u] = false;
        for (int x = 0; x < 50; x++)
        {
            if (adj[u][x] && dist[u]+1 < dist[x])
            {
                dist[x] = dist[u]+1;
                if (!vis[x])
                {
                    vis[x] = true;
                    buf.push(x);
                }
            }
        }
    }
    if (dist[b] == INT_MAX)
        printf("Not connected\n");
    else
        printf("%i\n", dist[b]);
}

int main()
{
    adj[2][6] = adj[6][2] = true;
    adj[1][6] = adj[6][1] = true;
    adj[7][6] = adj[6][7] = true;
    adj[3][6] = adj[6][3] = true;
    adj[4][6] = adj[6][4] = true;
    adj[5][6] = adj[6][5] = true;
    adj[3][4] = adj[4][3] = true;
    adj[4][5] = adj[5][4] = true;
    adj[3][5] = adj[5][3] = true;
    adj[3][15] = adj[15][3] = true;
    adj[13][15] = adj[15][13] = true;
    adj[12][13] = adj[13][12] = true;
    adj[13][14] = adj[14][13] = true;
    adj[7][8] = adj[8][7] = true;
    adj[8][9] = adj[9][8] = true;
    adj[9][10] = adj[10][9] = true;
    adj[12][9] = adj[9][12] = true;
    adj[11][12] = adj[12][11] = true;
    adj[10][11] = adj[11][10] = true;
    adj[16][18] = adj[18][16] = true;
    adj[16][17] = adj[17][16] = true;
    adj[17][18] = adj[18][17] = true;
    char t;
    int x, y;
    scanf(" %c", &t);
    while (t != 'q')
    {
        scanf("%i", &x);
        if (t != 'n' && t != 'f')
            scanf("%i", &y);
        switch(t)
        {
            case 'i':
                adj[x][y] = adj[y][x] = true;
            break;
            case 'd':
                adj[x][y] = adj[y][x] = false;
            break;
            case 'n':
            {
                int s = 0;
                for (int a = 0; a < 50; s += adj[x][a++]);
                printf("%i\n", s);
            }
            break;
            case 'f':
            {
                int s = 0;
                vector<bool> ff(50);
                for (int a = 0; a < 50; a++)
                    if (adj[x][a])
                        for (int b = 0; b < 50; b++)
                            if (b != x && adj[a][b] && !adj[x][b] && !ff[b])
                                s++, ff[b] = true;
                printf("%i\n", s);
            }
            break;
            case 's':
                BFS(x, y);
            break;
        }

        scanf(" %c", &t);
    }
}
