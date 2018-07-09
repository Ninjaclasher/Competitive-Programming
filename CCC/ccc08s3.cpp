#include <bits/stdc++.h>

using namespace std;

char graph[22][22];
int dist[22][22];

void BFS ()
{
    list<pair<int,int>> pq;
    pq.push_back(make_pair(1, 1));
    dist[1][1] = 0;
    while (!pq.empty())
    {
        int u = pq.front().first, v = pq.front().second;
        pq.pop_front();
        if (dist[u][v]+1 < dist[u+1][v] && graph[u+1][v] != '*' && (graph[u][v] == '+' || graph[u][v] == '|'))
        {
            dist[u+1][v] = dist[u][v] + 1;
            pq.push_back(make_pair(u+1, v));
        }
        if (dist[u][v]+1 < dist[u-1][v] && graph[u-1][v] != '*' && (graph[u][v] == '+' || graph[u][v] == '|'))
        {
            dist[u-1][v] = dist[u][v] + 1;
            pq.push_back(make_pair(u-1, v));
        }
        if (dist[u][v]+1 < dist[u][v+1] && graph[u][v+1] != '*' && (graph[u][v] == '+' || graph[u][v] == '-'))
        {
            dist[u][v+1] = dist[u][v] + 1;
            pq.push_back(make_pair(u, v+1));
        }
        if (dist[u][v]+1 < dist[u][v-1] && graph[u][v-1] != '*' && (graph[u][v] == '+' || graph[u][v] == '-'))
        {
            dist[u][v-1] = dist[u][v] + 1;
            pq.push_back(make_pair(u, v-1));
        }
    }
}

int main()
{
    int t, r, c;
    scanf("%i", &t);
    for (int a = 0; a < t; a++)
    {
        scanf("%i%i", &r, &c);
        for (int x = 0; x < 22; x++)
            for (int y = 0; y < 22; y++)
                graph[x][y] = '*', dist[x][y] = INT_MAX;
        for (int x = 1; x <= r; x++)
            for (int y = 1; y <= c; y++)
                scanf(" %c", &graph[x][y]);
        BFS();
        if (dist[r][c] == INT_MAX)
            printf("-1\n");
        else
            printf("%i\n", dist[r][c]+1);
    }
    return 0;
}
