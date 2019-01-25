#include <bits/stdc++.h>

using namespace std;

const int MAXX = 103;

int dist[MAXX][MAXX][30][30];
bool bad[MAXX][MAXX], vis[MAXX][MAXX][30][30];

struct state
{
    int x, y, xvel, yvel;
};

int X, Y;

bool bo(int x, int y)
{
    return x >= 0 && x <= X && y >= 0 && y <= Y;
}

int main()
{
    memset(dist, 0x3f, sizeof (dist));
    int n, a, b, c, d, e, f;
    scanf("%i%i%i", &X, &Y, &n);
    scanf("%i%i%i%i", &a, &b, &c, &d);
    while (n--)
    {
        scanf("%i%i", &e, &f);
        bad[e][f] = 1;
    }
    queue<state> buf;
    buf.push({a, b, 14, 14});
 dist[a][b][14][14] = 0;
    while (!buf.empty())
    {
        state u = buf.front();
        buf.pop();
        vis[u.x][u.y][u.xvel][u.yvel] = 0;
        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                if (x == 0 || y == 0)
                {
                    int xv = u.xvel + x, yv = u.yvel + y;
                    int axv = xv - 14, ayv = yv - 14;
                    if (abs(axv) > 13 || abs(ayv) > 13)
                        goto nxt;
                    if (axv == 0)
                    {
                        if (ayv == 0)
                            goto nxt2;
                        {
                        int dir = ayv / abs(ayv);
                        for (int i = 1; i <= abs(ayv); i++)
                            if (!bo(u.x, u.y + dir * i) || bad[u.x][u.y + dir * i])
                                goto nxt;
                        }
                    }
                    else if (ayv == 0)
                    {
                        int dir = axv / abs(axv);
                        for (int i = 1; i <= abs(axv); i++)
                            if (!bo(u.x + dir * i, u.y) || bad[u.x + dir * i][u.y])
                                goto nxt;
                    }
                    else
                    {
                        int gg = abs(__gcd(axv, ayv));
                        int jx = axv / gg, jy = ayv / gg;
                        for (int i = 1; abs(i * jx) <= abs(axv); i++)
                            if (!bo(u.x + i * jx, u.y + i * jy) || bad[u.x + i * jx][u.y + i * jy])
                                goto nxt;
                    }
nxt2:;
                    if (dist[u.x + axv][u.y + ayv][xv][yv] > dist[u.x][u.y][u.xvel][u.yvel] + 1)
                    {
                        dist[u.x + axv][u.y + ayv][xv][yv] = dist[u.x][u.y][u.xvel][u.yvel] + 1;
                        if (!vis[u.x + axv][u.y + ayv][xv][yv])
                        {
                            vis[u.x + axv][u.y + ayv][xv][yv] = 1;
                            buf.push({u.x + axv, u.y + ayv, xv, yv});
                        }
                    }
nxt:;
                }
            }
        }
    }
    if (dist[c][d][14][14] > 3000)
        printf("-1\n");
    else
        printf("%i\n", dist[c][d][14][14]);
}
