#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, g;
    scanf("%i%i", &n, &g);
    bool grid[n][n];
    map<int,int> cnt;
    long long ans = 0;
    while (g--)
    {
        char c;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                scanf(" %c", &c);
                grid[x][y] = (c == 'W');
            }
        }
        for (int x = 0; x < n-1; x++)
        {
            for (int y = 0; y < n-1; y++)
            {
                if (grid[x][y])
                {
                    for (int i = 0; i <= 1; i++)
                        for (int j = 0; j <= 1; j++)
                            grid[x+i][y+j] ^= 1;
                }
            }
        }
        int msk = 0;
        for (int x = 0; x < n; x++)
            msk = msk<<1|grid[x][n-1];
        for (int x = 0; x < n; x++)
            msk = msk<<1|grid[n-1][x];
        ans += cnt[msk];
        cnt[msk]++;
    }
    printf("%lli\n", ans);
}
