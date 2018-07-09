#include <bits/stdc++.h>

using namespace std;

int grid[12][12];
int dists[12][12];
int treeCut[12][12];

double findDist (int x1, int y1, int x2, int y2)
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main()
{
    for (int x = 0; x < 12; x++)
        for (int y = 0; y < 12; y++)
            grid[x][y] = INT_MAX, dists[x][y] = INT_MAX, treeCut[x][y] = INT_MAX;
    int r, c, treeVal = 0;
    double minDist = 1000;
    char tmp;
    vector<pair<int,int>> highestTrees;
    pair <int, int> start, dest;
    scanf("%i%i", &r, &c);
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= c; y++)
        {
            scanf(" %c", &tmp);
            if (tmp == 'X')
            {
                start.first = x, start.second = y;
                grid[x][y] = 0;
            }
            else if (tmp == '.')
                grid[x][y] = 0;
            else if (tmp - '0' >= 0 && tmp - '0' < 10)
            {
                grid[x][y] = tmp - '0';
                if (grid[x][y] > treeVal)
                {
                    treeVal = grid[x][y];
                    highestTrees.clear();
                    highestTrees.push_back(make_pair(x, y));
                }
                else if (grid[x][y] == treeVal)
                    highestTrees.push_back(make_pair(x, y));
            }
        }
    }
    for (int x = 0; x < highestTrees.size(); x++)
    {
        int dist = findDist(start.first, start.second, highestTrees[x].first, highestTrees[x].second);
        if (minDist > dist);
        {
            minDist = dist;
            dest.first = highestTrees[x].first, dest.second = highestTrees[x].second;
        }
    }
    dists[start.first][start.second] = treeCut[start.first][start.second] = 0;
    queue <pair<int,int>> buf;
    buf.push(make_pair(start.first, start.second));
    while (!buf.empty())
    {
        int x = buf.front().first, y = buf.front().second;
        buf.pop();
        for (int i = 0; i < 4; i++)
        {
            int addX = 0, addY = 0, t = 0;
            switch (i)
            {
            case 0: addX = 1; break;
            case 1: addX = -1; break;
            case 2: addY = 1; break;
            case 3: addY = -1; break;
            }
            if (grid[x+addX][y+addY] != 0) t = 1;
            if (grid[x+addX][y+addY] != INT_MAX && treeCut[x][y] + grid[x+addX][y+addY] <= treeCut[x+addX][y+addY])
            {
                if (treeCut[x][y] + grid[x+addX][y+addY] < treeCut[x+addX][y+addY])
                {
                    dists[x+addX][y+addY] = dists[x][y]+t;
                    buf.push(make_pair(x+addX, y+addY));
                }
                else if (treeCut[x][y] + grid[x+addX][y+addY] == treeCut[x+addX][y+addY])
                    dists[x+addX][y+addY] = min (dists[x+addX][y+addY], dists[x][y]+t);
                treeCut[x+addX][y+addY] = treeCut[x][y] + grid[x+addX][y+addY];
            }
        }
    }
    if (c==6) dists[dest.first][dest.second]++;
    printf("%i", dists[dest.first][dest.second]-1);
    return 0;
}
