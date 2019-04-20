#include <bits/stdc++.h>

using namespace std;

vector<long long> good_grids;

int grid[4][4];

void dfs(int i)
{
    if (i == 4)
    {
        for (int x = 0; x < 4; x++)
        {
            bool have[4] = {0, 0, 0, 0};
            for (int y = 0; y < 4; y++)
                have[grid[y][x]] = 1;
            for (int y = 0; y < 4; y++)
                if (!have[y])
                    return;
        }
        for (int x = 0; x < 4; x+=2)
        {
            for (int y = 0; y < 4; y+=2)
            {
                bool have[4] = {0, 0, 0, 0};
                for (int xx = 0; xx <= 1; xx++)
                    for (int yy = 0; yy <= 1; yy++)
                        have[grid[x+xx][y+yy]] = 1;
                for (int z = 0; z < 4; z++)
                    if (!have[z])
                        return;
            }
        }
        long long ret = 0;
        for (int x = 0; x < 4; x++)
            for (int y = 0; y < 4; y++)
                ret = (ret<<2) | grid[x][y];
        good_grids.push_back(ret);
        return;
    }
    int perm[4] = {0, 1, 2, 3};
    do
    {
        for (int x = 0; x < 4; x++)
            grid[i][x] = perm[x];
        dfs(i+1);
    }
    while(next_permutation(perm, perm+4));
}

inline void print(long long msk)
{
    for (int x = 3; x >= 0; x--)
        for (int y = 3; y >= 0; y--)
            grid[x][y] = (msk&3)+1, msk>>=2;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
            printf("%i", grid[x][y]);
        printf("\n");
    }
}

int main()
{
    dfs(0);
    int q;
    char c;
    scanf("%i", &q);
    while (q--)
    {
        long long chkmsk = 0, msk = 0;
        for (int x = 0; x < 4; x++)
        {
            getchar();
            for (int y = 0; y < 4; y++)
            {
                c = getchar();
                if (c == 'X')
                    chkmsk <<= 2, msk <<= 2;
                else
                    chkmsk = chkmsk<<2|3, msk = msk<<2|(c-'1');
            }
        }
        for (auto &z : good_grids)
        {
            if ((chkmsk&z) == msk)
            {
                print(z);
                break;
            }
        }
    }
}
