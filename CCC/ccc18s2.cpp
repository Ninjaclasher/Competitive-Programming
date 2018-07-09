#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    scanf("%i", &n);
    vector<vector<int>> aa(n, vector<int>(n));
    for (auto &x : aa)
        for (auto &y : x)
            scanf("%i", &y);
    vector<pair<int,int>> b;

    for (int x = 1; x < n; x++)
        for (int y = 1; y < n; y++)
            if (aa[x][y] < aa[x-1][y] || aa[x][y] < aa[x][y-1])
                goto n1;
    for (auto &x : aa)
    {
        for (auto &y : x)
            printf("%i ", y);
        printf("\n");
    }
    return 0;
    n1:;
    for (int x = 1; x < n; x++)
        for (int y = 1; y < n; y++)
            if (aa[x][y] > aa[x-1][y] || aa[x][y] > aa[x][y-1])
                goto n2;
    for (int x = n-1; x >= 0; x--)
    {
        for (int y = n-1; y >= 0; y--)
            printf("%i ", aa[x][y]);
        printf("\n");
    }
    return 0;
    n2:;
    vector<vector<int>> bb(n, vector<int>(n));
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            bb[y][n-x-1] = aa[x][y];
    }
    aa = bb;
    for (int x = 1; x < n; x++)
        for (int y = 1; y < n; y++)
            if (aa[x][y] < aa[x-1][y] || aa[x][y] < aa[x][y-1])
                goto n3;
    for (auto &x : aa)
    {
        for (auto &y : x)
            printf("%i ", y);
        printf("\n");
    }
    return 0;
    n3:;
    for (int x = 1; x < n; x++)
        for (int y = 1; y < n; y++)
            if (aa[x][y] > aa[x-1][y] || aa[x][y] > aa[x][y-1])
                goto n4;
    for (int x = n-1; x >= 0; x--)
    {
        for (int y = n-1; y >= 0; y--)
            printf("%i ", aa[x][y]);
        printf("\n");
    }
    return 0;
    n4:;
    abort();
}
