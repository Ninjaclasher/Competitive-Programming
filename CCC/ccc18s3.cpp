#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> aa(100, vector<char>(100));
vector<vector<bool>> hh(100, vector<bool>(100));

bool cc(int x, int y)
{
    switch(aa[x][y]){
        case 'L':
        case 'R':
        case 'U':
        case 'D':
            return true;
    }
    return false;
}

bool val(int x, int y)
{
    return (!hh[x][y] && aa[x][y] != 'W' && aa[x][y] != 'C') || cc(x, y);
}


int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    vector<pair<int,int>> cam;

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            scanf(" %c", &aa[x][y]);
            if (aa[x][y] == 'S')
                a = x, b = y;
            if (aa[x][y] == 'C')
                cam.push_back({x, y});
        }
    }
    for (auto &x : cam)
    {
        queue<pair<int,pair<int,int>>> buf;
        for (int xx = x.first-1; xx > 0; xx--)
            if (aa[xx][x.second] == 'W')
                break;
            else if (!cc(xx,x.second))
                hh[xx][x.second] = 'H';
        for (int xx = x.first+1; xx < n; xx++)
            if (aa[xx][x.second] == 'W')
                break;
            else if (!cc(xx,x.second))
                hh[xx][x.second] = 'H';
        for (int y = x.second-1; y > 0; y--)   
            if (aa[x.first][y] == 'W')
                break;
            else if (!cc(x.first,y))
                hh[x.first][y] ='H';
        for (int y = x.second+1; y < m; y++)   
            if (aa[x.first][y] == 'W')
                break;
            else if (!cc(x.first,y))
                hh[x.first][y] ='H';
    }
    queue<pair<int,int>> buf;
    buf.push({a, b});
    vector<vector<int>> dist(100, vector<int> (100, INT_MAX));
    if (!hh[a][b])
    {
        dist[a][b] = 0;
        while (!buf.empty())
        {
            int x = buf.front().first, y = buf.front().second;
            if (!val(x, y))
                abort();
            buf.pop();
            int ax = 0, ay = 0;
            switch(aa[x][y])
            {
                case 'U':
                    ax--; break;
                case 'D':
                    ax++; break;
                case 'L':
                    ay--; break;
                case 'R':
                    ay++; break;
                default:
                    for (int i = 0; i < 4; i++)
                    {
                        ax = 0, ay = 0;
                        switch(i)
                        {
                            case 0: ax++; break;
                            case 1: ax--; break;
                            case 2: ay++; break;
                            case 3: ay--; break;
                        }
                        if (val(x+ax, y+ay) && dist[x+ax][y+ay] > dist[x][y]+1)
                        {
                            dist[x+ax][y+ay] = dist[x][y]+1;
                            buf.push({x+ax, y+ay});
                        }
                    }
                goto aaaa;
            }
            if (val(x+ax, y+ay) && dist[x+ax][y+ay] > dist[x][y])
            {
                dist[x+ax][y+ay] = dist[x][y];
                buf.push({x+ax, y+ay});
            }
            aaaa:;
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (aa[x][y] == '.')
                printf("%i\n", dist[x][y] == INT_MAX ? -1 : dist[x][y]);
        }
    }
}
