#include <bits/stdc++.h>

using namespace std;

int hist[450][450];

int main()
{
    int r, c, ma = 0;
    scanf("%i%i", &r, &c);
    vector<vector<char>> arr(450, vector<char>(450, 'X'));
    for (int x = 1; x <= r; x++)
        for (int y = 1; y <= c; y++)
            scanf(" %c", &arr[x][y]);
    for (int x = r+1; x >= 0; x--)
        for (int y = 0; y <= c+1; y++)
            hist[x][y] = (arr[x][y] == 'X') ? 0 : hist[x+1][y]+1;
    for (int x = 0; x <= r+1; x++)
    {
        stack<int> ms;
        vector<vector<int>> pos(2, vector<int>(c+1));
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
        {
            if (!hist[x][y])
                continue;
            ma = max(ma, 2*(pos[1][y]-pos[0][y] + hist[x][y]));
        }
    }
    printf("%i\n", ma-1);
}

