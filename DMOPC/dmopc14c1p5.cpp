#include<bits/stdc++.h>

using namespace std;

char grid[1000][1000];
int dist[1000][1000];
bool tel[1000][1000];
bool visited[1000][1000];

int BFS(int r, int c, int startX, int startY)
{
    int minT = INT_MAX, d;
    visited[startX][startY] = true;
    for (int x = 0; x < r; x++)
        for (int y = 0; y < c; y++)
            dist[x][y] = INT_MAX;
    dist[startX][startY] = 0;
    list <pair<int,int>> l;
    l.push_back(make_pair(startX, startY));
    while (!l.empty())
    {
        int f = l.front().first, s = l.front().second;
        d = dist[f][s] + 1;
        l.pop_front();
        if (tel[f][s])
            minT = min(minT, dist[f][s]);
        if (grid[f+1][s] == 'O')
        {
            dist[f+1][s] = min(d, dist[f+1][s]);
            if (!visited[f+1][s])
            {
                visited[f+1][s] = true;
                l.push_back(make_pair(f+1, s));
            }
        }
        if (grid[f-1][s] == 'O')
        {
            dist[f-1][s] = min(d,dist[f-1][s]);
            if (!visited[f-1][s])
            {
                visited[f-1][s] = true;
                l.push_back(make_pair(f-1, s));
            }
        }
        if (grid[f][s+1] == 'O')
        {
            dist[f][s+1] = min(d, dist[f][s+1]);
            if (!visited[f][s+1])
            {
                visited[f][s+1] = true;
                l.push_back(make_pair(f, s+1));
            }
        }
        if (grid[f][s-1] == 'O')
        {
            dist[f][s-1] = min(d, dist[f][s-1]);
            if (!visited[f][s-1])
            {
                visited[f][s-1] = true;
                l.push_back(make_pair(f, s-1));
            }
        }
    }
    return minT;
}

int main()
{
    int r, c, startX, startY, endX, endY, t, posX, posY;
    scanf("%i%i%i%i%i%i", &r, &c, &startX, &startY, &endX, &endY);
    for (int x = 0; x < r; x++)
        for (int y = 0; y < c; y++)
            scanf(" %c", &grid[x][y]);
    scanf("%i", &t);
    for (int x = 0; x < t; x++)
    {
        scanf("%i%i", &posX, &posY);
        tel[posX][posY] = true;
    }
    int p = BFS(r, c, startX, startY);
    printf("%i", dist[endX][endY] - p);
    return 0;
}
