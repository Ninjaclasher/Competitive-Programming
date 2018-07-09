#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int r, c,  t = 0;
    scanf("%i%i", &r, &c);
    vector<vector<char>> g(r+2, vector<char>(c+2, 'X'));
    for (int x = 1; x <= r; x++)
        for (int y = 1; y <= c; y++)
            scanf(" %c", &g[x][y]);
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= c; y++)
        {
            if (g[x][y] == '.')
            {
                g[x][y] = 'X';
                t++;
                queue<pair<int,int>> buf;
                buf.push(make_pair(x, y));
                while (!buf.empty())
                {
                    int xx = buf.front().first, yy = buf.front().second;
                    buf.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int xa = 0, ya = 0;
                        switch(i)
                        {
                            case 0: xa++; break;
                            case 1: xa--; break;
                            case 2: ya++; break;
                            case 3: ya--; break;
                        }
                        if (g[xx+xa][yy+ya] == '.')
                            g[xx+xa][yy+ya] = 'X', buf.push(make_pair(xx+xa, yy+ya));
                    }
                }
            }
        }
    }
    printf("%i", t);
    return 0;
}
