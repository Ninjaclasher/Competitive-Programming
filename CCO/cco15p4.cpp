#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> lot;
int n, m;
set<pair<int,int>> aa;

void dfs(int a, int b)
{
    switch(lot[a][b])
    {
        case 'S':
            for (int x = a+1; x < n; x++)
                if (lot[x][b] != '.')
                    dfs(x, b);
        break;
        case 'N':
            for (int x = a-1; x >= 0; x--)
                if (lot[x][b] != '.')
                    dfs(x, b);
        break;
        case 'E':
            for (int x = b+1; x < m; x++)
                if (lot[a][x] != '.')
                    dfs(a, x);
        break;
        case 'W':
            for (int x = b-1; x >= 0; x--)
                if (lot[a][x] != '.')
                    dfs(a, x);
        break;
    }
    aa.erase(make_pair(a, b));
    lot[a][b] = '.';
    printf("(%i,%i)\n", a, b);
}

int main()
{
    scanf("%i%i", &n, &m);
    lot.resize(n);
    fill(lot.begin(), lot.end(), vector<char>(m));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            scanf(" %c", &lot[x][y]);
            if (lot[x][y] != '.')
                aa.insert(make_pair(x, y));
        }
    }
    while (!aa.empty())
        dfs(aa.begin()->first, aa.begin()->second);
}
