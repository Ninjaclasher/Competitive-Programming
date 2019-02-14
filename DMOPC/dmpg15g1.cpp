#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<vector<char>> good(n, vector<char>(n));
    vector<vector<int>> up(n, vector<int>(n));
    vector<vector<int>> left(n, vector<int>(n));
    char c;
    for (auto &x : good)
    {
        for (auto &y : x)
        {
            scanf(" %c", &c);
            y = (c =='.');
        }
    }
    for (int x = n-1; x >= 0; x--)
    {
        for (int y = 0; y < n; y++)
        {
            if (x == n-1)
                up[x][y] = good[x][y];
            else if (!good[x][y])
                up[x][y] = 0;
            else
                up[x][y] = up[x+1][y] + 1;
        }
    }
    for (int y = n-1; y >= 0; y--)
    {
        for (int x = 0; x < n; x++)
        {
            if (y == n-1)
                left[x][y] = good[x][y];
            else if (!good[x][y])
                left[x][y] = 0;
            else
                left[x][y] = left[x][y+1] + 1;
        }
    }
    for (int x = n+1; x >= 0; x--)
    {
        bool pos = false;
        for (int y = 0; y < n-x+1 && !pos; y++)
        {
            for (int z = 0; z < n-x+1 && !pos; z++)
            {
                if (up[y][z] >= x && left[y][z] >= x && left[y+x-1][z] >= x && up[y][z+x-1] >= x)
                    pos = true;
            }
        }
        if (pos)
            return 0 * printf("%i\n", x-1);
    }
}
