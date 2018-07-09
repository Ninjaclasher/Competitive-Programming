#include <bits/stdc++.h>

using namespace std;

char floods[52][52][2500];
int dist[52][52];
vector <pair<int,int>> floodLocate;

void Flood(int r, int c)
{
    int sizes = r*c;
    list<pair<int,int>> pq[sizes];
    for (int x = 0; x < floodLocate.size(); x++)
        pq[0].push_back(floodLocate[x]);
    for (int x = 0; x < sizes; x++)
    {
        while (!pq[x].empty())
        {
            int u = pq[x].front().first, v = pq[x].front().second;
            pq[x].pop_front();
            if (floods[u+1][v][x] == '.')
            {
                for (int y = x; y < sizes; y++)
                    floods[u+1][v][y] = '*';
                pq[x+1].push_back(make_pair(u+1, v));
            }
            if (floods[u-1][v][x] == '.')
            {
                for (int y = x; y < sizes; y++)
                    floods[u-1][v][y] = '*';
                pq[x+1].push_back(make_pair(u-1, v));
            }
            if (floods[u][v+1][x] == '.')
            {
                for (int y = x; y < sizes; y++)
                    floods[u][v+1][y] = '*';
                pq[x+1].push_back(make_pair(u, v+1));
            }
            if (floods[u][v-1][x] == '.')
            {
                for (int y = x; y < sizes; y++)
                    floods[u][v-1][y] = '*';
                pq[x+1].push_back(make_pair(u, v-1));
            }
        }
    }
}

void BFS (int sX, int sY)
{
    list<pair<int,int>> pq;
    pq.push_back(make_pair(sX, sY));
    dist[sX][sY] = 0;
    while (!pq.empty())
    {
        int u = pq.front().first, v = pq.front().second;
        pq.pop_front();
        if (dist[u][v]+1 < dist[u+1][v] && (floods[u+1][v][dist[u][v]] == '.' || floods[u+1][v][dist[u][v]] == 'D'))
        {
            dist[u+1][v] = dist[u][v] + 1;
            pq.push_back(make_pair(u+1, v));
        }
        if (dist[u][v]+1 < dist[u-1][v] && (floods[u-1][v][dist[u][v]] == '.' || floods[u-1][v][dist[u][v]] == 'D'))
        {
            dist[u-1][v] = dist[u][v] + 1;
            pq.push_back(make_pair(u-1, v));
        }
        if (dist[u][v]+1 < dist[u][v+1] && (floods[u][v+1][dist[u][v]] == '.' || floods[u][v+1][dist[u][v]] == 'D'))
        {
            dist[u][v+1] = dist[u][v] + 1;
            pq.push_back(make_pair(u, v+1));
        }
        if (dist[u][v]+1 < dist[u][v-1] && (floods[u][v-1][dist[u][v]] == '.' || floods[u][v-1][dist[u][v]] == 'D'))
        {
            dist[u][v-1] = dist[u][v] + 1;
            pq.push_back(make_pair(u, v-1));
        }
    }
}

int main()
{
    int r, c, startX, startY, endX, endY;
    for (int x = 0; x < 52; x++)
    {
        for (int y = 0; y < 52; y++)
        {
            dist[x][y] = INT_MAX;
            for (int z = 0; z < 2500; z++)
                floods[x][y][z] = 'X';
        }
    }
    scanf("%i%i", &r, &c);
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= c; y++)
        {
            scanf(" %c", &floods[x][y][0]);
            switch(floods[x][y][0])
            {
            case 'S':
                startX = x, startY = y;
                floods[x][y][0] = '.';
                break;
            case 'D':
                endX = x, endY = y;
                break;
            case '*':
                floodLocate.push_back(make_pair(x, y));
                break;
            }
            for (int z = 1; z < r*c; z++)
                floods[x][y][z] = floods[x][y][0];
        }
    }
    Flood(r, c);
    BFS(startX, startY);
    if (dist[endX][endY] == INT_MAX)
        printf("KAKTUS");
    else
        printf("%i", dist[endX][endY]);
    return 0;
}
