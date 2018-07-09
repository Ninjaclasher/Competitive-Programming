#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

int dist[8][8];

void shortestPath(int startX, int startY)
{
    list<iPair> pq;
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++)
        dist[x][y] = 100;
    dist[startX][startY] = 0;
    pq.push_back(make_pair(startX, startY));
    while (!pq.empty())
    {
        int u = pq.front().first, v = pq.front().second, uu, vv;
        pq.pop_front();
        for (int x = 0; x < 8; x++)
        {
            switch (x)
            {
            case 0: uu = u + 2, vv = v + 1; break;
            case 1: uu = u + 2, vv = v - 1; break;
            case 2: uu = u + 1, vv = v + 2; break;
            case 3: uu = u + 1, vv = v - 2; break;
            case 4: uu = u - 2, vv = v + 1; break;
            case 5: uu = u - 2, vv = v - 1; break;
            case 6: uu = u - 1, vv = v + 2; break;
            case 7: uu = u - 1, vv = v - 2; break;
            }
            if (uu < 8 && vv < 8 && uu >= 0 && vv >= 0 && dist[u][v] + 1 < dist[uu][vv])
            {
                dist[uu][vv] = dist[u][v] + 1;
                pq.push_back(make_pair(uu, vv));
            }
        }
    }
}

int main()
{
    int x1, y1, x2, y2;
    scanf("%i%i%i%i", &x1, &y1, &x2, &y2);
    shortestPath(x1-1, y1-1);
    printf("%i", dist[x2-1][y2-1]);
    return 0;
}
