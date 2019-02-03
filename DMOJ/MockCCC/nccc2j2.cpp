#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<vector<char>> arr(n, vector<char>(m));
    for (auto &x : arr)
        for (auto &y : x)
            scanf(" %c", &y);
    for (int i = 0; i < 100; i++)
    {
        for (int x = 0; x < n-1; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (arr[x][y] == 'o' && arr[x+1][y] == '.')
                    swap(arr[x][y], arr[x+1][y]);
            }
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
            printf("%c", arr[x][y]);
        printf("\n");
    }
}

