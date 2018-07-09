#include <bits/stdc++.h>

using namespace std;

int arr[152][152][152], dist[152][152][152];

struct pp
{
    int x, y, z;
};

int main()
{
    int a, b, c, aa, bb, cc, mw = INT_MAX;
    char t;
    scanf("%i%i%i", &a, &b, &c);
    for (int x = 1; x <= a; x++)
        for (int y = 1; y <= b; y++)
            for (int z = 1; z <= c; z++)
            {
                scanf(" %c", &t);
                if (t == 'J')
                    aa = x, bb = y, cc = z;
                else
                    arr[x][y][z] = t-'0';
            }
    fill((int*)dist, (int*)dist+3511809, INT_MAX);
    queue<pp> buf;
    buf.push({aa, bb, cc});
    dist[aa][bb][cc] = 0;
    while (!buf.empty())
    {
        int xx = buf.front().x, yy = buf.front().y, zz = buf.front().z;
        buf.pop();
        if (dist[xx][yy][zz] > mw) continue;
        for (int i = 0; i < 6; i++)
        {
            int x = 0, y = 0, z = 0;
            switch(i)
            {
                case 0: x++; break;
                case 1: x--; break;
                case 2: y++; break;
                case 3: y--; break;
                case 4: z++; break;
                case 5: z--; break;
            }
            if (xx + x < 1 || yy + y < 1 || zz + z < 1 || xx + x > a || yy + y > b || zz + z > c)
                mw = min(mw, dist[xx][yy][zz]);
            else if (dist[xx+x][yy+y][zz+z] > dist[xx][yy][zz]+arr[xx+x][yy+y][zz+z])
                dist[xx+x][yy+y][zz+z] = dist[xx][yy][zz]+arr[xx+x][yy+y][zz+z], buf.push({xx+x, yy+y, zz+z});
        }
    }
    printf("%i", mw);
}
