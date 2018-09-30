#include <bits/stdc++.h>

using namespace std;

int arr[200][200], psa[200][200];

int query(int x2, int y2, int x1, int y1)
{
    return psa[x2][y2]-psa[x2][y1-1]-psa[x1-1][y2]+psa[x1-1][y1-1];
}

int main()
{
    int n, m, a, b;
    int ans = 0;
    scanf("%i%i", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i", &a, &b);
        if (!arr[a][b])
            arr[a][b] = 1;
    }
    int mi = INT_MAX;
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            psa[x][y] = psa[x-1][y] + psa[x][y-1] - psa[x-1][y-1] + arr[x][y];
    for (int x = 1; x <= m; x++)
    {
        if (m%x == 0)
        {
            int y = m/x;
            for (int i = x; i <= n; i++)
                for (int j = y; j <= n; j++)
                    mi = min(mi, m-query(i, j, i-x+1, j-y+1));
        }
    }
    printf("%i\n", mi);
}

