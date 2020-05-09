#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<vector<int>> arr(n, vector<int>(n));
    vector<int> mv, mvv;
    for (auto &x : arr)
        for (auto &y : x)
            scanf("%i", &y);
    for (int x = 1; x < n; x++)
    {
        if (arr[x][0] != arr[x-1][0])
        {
            mv.push_back(x);
            for (int y = 0; y < n; y++)
            {
                arr[x][y] ^= 1;
                if (arr[x][y] != arr[x-1][y])
                    return 0 * printf("-1\n");
            }
        }
        else
            for (int y = 0; y < n; y++)
                if (arr[x][y] != arr[x-1][y])
                    return 0 * printf("-1\n");
    }
    for (int x = 0; x < n; x++)
        if (arr[0][x])
            mvv.push_back(x);
    printf("%lu\n", mv.size() + mvv.size());
    for (auto &x : mv)
        printf("R %i\n", x+1);
    for (auto &x : mvv)
        printf("C %i\n", x+1);
}
