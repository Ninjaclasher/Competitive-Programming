#include <bits/stdc++.h>

using namespace std;
char grid[52][52];
int dist[52][52];

void BFS (int startX, int startY)
{
    list<pair<int,int>> pq;
    pq.push_back(make_pair(startX, startY));
    dist[startX][startY] = 0;
    while (!pq.empty())
    {
        int u = pq.front().first, v = pq.front().second;
        pq.pop_front();
        if (grid[u+1][v] != 'X' && dist[u+1][v] > dist[u][v] + 1)
        {
            dist[u+1][v] = dist[u][v]+1;
            pq.push_back(make_pair(u+1, v));
        }
        if (grid[u-1][v] != 'X' && dist[u-1][v] > dist[u][v] + 1)
        {
            dist[u-1][v] = dist[u][v]+1;
            pq.push_back(make_pair(u-1, v));
        }
        if (grid[u][v+1] != 'X' && dist[u][v+1] > dist[u][v] + 1)
        {
            dist[u][v+1] = dist[u][v]+1;
            pq.push_back(make_pair(u, v+1));
        }
        if (grid[u][v-1] != 'X' && dist[u][v-1] > dist[u][v] + 1)
        {
            dist[u][v-1] = dist[u][v]+1;
            pq.push_back(make_pair(u, v-1));
        }
    }
}

int main()
{
    int t, l, w, compX, compY, washX, washY;
    scanf("%i", &t);
    for (int x = 0; x < t; x++)
    {
        for (int y = 0; y < 52; y++)
            for (int z = 0; z < 52; z++)
                grid[y][z] = 'X', dist[y][z] = INT_MAX;
        scanf("%i%i", &l, &w);
        for (int y = 1; y <= w; y++)
        {
            for (int z = 1; z <= l; z++)
            {
                scanf(" %c", &grid[y][z]);
                if (grid[y][z] == 'C')
                    compX = y, compY = z;
                else if (grid[y][z] == 'W')
                    washX = y, washY = z;
            }
        }
        BFS(compX, compY);
        if (dist[washX][washY] >= 60)
            printf("#notworth\n");
        else
            printf("%i\n", dist[washX][washY]);
    }
    return 0;
}
