#include <bits/stdc++.h>

using namespace std;

int hist[1005][1005], pos[2][1005];

int main()
{
    int k;
    scanf("%i", &k);
    while (k--)
    {
        memset(hist, 0, sizeof(hist));
        int r, c, ma = 0;
        scanf("%i%i", &r, &c);
        vector<vector<char>> arr(1005, vector<char>(1005, 'R'));
        for (int x = 1; x <= r; x++)
            for (int y = 1; y <= c; y++)
                scanf(" %c", &arr[x][y]);
        for (int x = r+1; x >= 0; x--)
            for (int y = 0; y <= c+1; y++)
                hist[x][y] = (arr[x][y] == 'R') ? 0 : hist[x+1][y]+1;
        for (int x = 0; x <= r+1; x++)
        {
            stack<int> ms;
            for (int y = 0; y <= c+1; y++)
            {
                while (!ms.empty() && hist[x][ms.top()] >= hist[x][y])
                    ms.pop();
                pos[0][y] = ms.empty() ? 0 : ms.top();
                ms.push(y);
            }
            while (!ms.empty()) ms.pop();
            for (int y = c+1; y >= 0; y--)
            {
                while (!ms.empty() && hist[x][ms.top()] >= hist[x][y])
                    ms.pop();
                pos[1][y] = (ms.empty() ? c+1 : ms.top()-1);
                ms.push(y);
            }
            for (int y = 0; y <= c+1; y++)
                ma = max(ma, (pos[1][y]-pos[0][y])*hist[x][y]);
        }
        printf("%i\n", ma*3);
    }
}

