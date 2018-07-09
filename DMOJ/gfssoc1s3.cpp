#include<bits/stdc++.h>
using namespace std;

int huntDist[6][6];
char graph[22][22];
vector <pair<int,int>> locations;
int griffy, n, m, t, cost = 999;

void BFS(int src)
{
    int dist[22][22];
    bool vis[22][22];
    for (int x = 0; x < n+1; x++)
        for (int y = 0; y < m+1; y++)
            dist[x][y] = 100000000, vis[x][y] = false;
    list<pair<int,int>> pq;
    dist[locations[src].first][locations[src].second] = 0;
    pq.push_back(make_pair(locations[src].first, locations[src].second));
    while (!pq.empty())
    {
        int u = pq.front().first;
        int v = pq.front().second;
        pq.pop_front();
        vis[u][v] = false;
        if (graph[u+1][v] != 'X' && dist[u][v] + 1 < dist[u+1][v])
        {
            dist[u+1][v] = dist[u][v] + 1;
            if (!vis[u+1][v])
            {
                vis[u+1][v] = true;
                pq.push_back(make_pair(u+1, v));
            }
        }
        if (graph[u-1][v] != 'X' && dist[u][v] + 1 < dist[u-1][v])
        {
            dist[u-1][v] = dist[u][v] + 1;
            if (!vis[u-1][v])
            {
                vis[u-1][v] = true;
                pq.push_back(make_pair(u-1, v));
            }
        }
        if (graph[u][v+1] != 'X' && dist[u][v] + 1 < dist[u][v+1])
        {
            dist[u][v+1] = dist[u][v] + 1;
            if (!vis[u][v+1])
            {
                vis[u][v+1] = true;
                pq.push_back(make_pair(u, v+1));
            }
        }
        if (graph[u][v-1] != 'X' && dist[u][v] + 1 < dist[u][v-1])
        {
            dist[u][v-1] = dist[u][v] + 1;
            if (!vis[u][v-1])
            {
                vis[u][v-1] = true;
                pq.push_back(make_pair(u, v-1));
            }
        }
    }
    for (int x = 0; x < locations.size(); x++)
        huntDist[src][x] = dist[locations[x].first][locations[x].second];
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void copy_array(int *a)
{
    int sum = 0, l = 0;
    int path[t];
    for (int i = 0; i < t; i++)
    {
        sum += huntDist[a[i]][a[(i + 1)]];
        path[i] = a[i];
    }
    path[t] = a[t-1%t+1];
    for (int x = 0; x <= t; x++)
        if (path[x] == griffy-1)
            l = x;
    if (l != 0 && l!= t)
        sum+= min(huntDist[a[0]][a[l]],huntDist[a[l]][a[t]]);
    cost = min(cost, sum);
}

void permute(int *a, int i)
{
    if (i == t-1)
        copy_array(a);
    else
    {
        for (int j = i; j < t; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1);
            swap((a + i), (a + j));
        }
    }
}

int main()
{
    for (int x = 0; x < 22; x++)
        for (int y = 0; y < 22; y++)
            graph[x][y] = 'X';
    scanf("%i%i%i", &n, &m, &t);
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            scanf(" %c", &graph[x][y]);
            if (graph[x][y] == 'H')
                locations.push_back(make_pair(x, y));
            else if (graph[x][y] == 'G')
            {
                locations.push_back(make_pair(x, y));
                griffy = locations.size();
            }
        }
    }
    for (int x = 0; x <= t; x++)
        BFS(x);
    int a[] = {0,1,2,3,4,5};
    permute(a, 0);
    printf("%i", cost);
    return 0;
}
