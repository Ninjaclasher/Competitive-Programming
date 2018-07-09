#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dist(27), graph(27);

void BFS()
{
    queue<pair<int, int>> buf;
    dist[1][1] = 0;
    buf.push(make_pair(1, 1));
    while (!buf.empty())
    {
        int x = buf.front().first, y = buf.front().second;
        buf.pop();
        for (int i = 0; i < 4; i++)
        {
            int xAdd = 0, yAdd = 0;
            switch (i)
            {
                case 0: xAdd++; break;
                case 1: xAdd--; break;
                case 2: yAdd++; break;
                case 3: yAdd--; break;
            }
            int o = graph[x+xAdd][y+yAdd] > graph[1][1] || graph[x][y] > graph[1][1];
            if (graph[x+xAdd][y+yAdd] != INT_MAX && abs(graph[x+xAdd][y+yAdd] - graph[x][y]) < 3 && dist[x][y] + o < dist[x+xAdd][y+yAdd])
            {
                dist[x+xAdd][y+yAdd] = dist[x][y] + o;
                buf.push(make_pair(x+xAdd, y+yAdd));
            }
        }
    }
}

int main()
{
    int t, n;
    scanf("%i", &t);
    while (t--)
    {
        fill(dist.begin(), dist.end(), vector<int> (27, INT_MAX));
        fill(graph.begin(), graph.end(), vector<int> (27, INT_MAX));
        scanf("%i", &n);
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= n; y++)
                scanf("%i", &graph[x][y]);
        BFS();
        if (dist[n][n] == INT_MAX)
            printf("CANNOT MAKE THE TRIP");
        else
            printf("%i", dist[n][n]);
        if (t)
            printf("\n\n");
    }
    return 0;
}
