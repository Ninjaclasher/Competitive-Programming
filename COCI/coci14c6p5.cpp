#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, s;
    scanf("%i%i", &r, &s);
    vector<vector<int>> arr(r+1, vector<int>(s+2)), gr(r+1, vector<int>(s+2));
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= s; y++)
        {
            scanf("%i", &arr[x][y]);
            if (x > 1 && y > 1 && arr[x-1][y-1] + arr[x][y] <= arr[x-1][y] + arr[x][y-1])
                gr[x][y] = 1;
        }
    }
    for (int x = 1; x <= r; x++)
        for (int y = 1; y <= s; y++)
            if (gr[x][y])
                gr[x][y] += gr[x-1][y];
    int ma = 0;
    for (int x = 1; x <= r; x++)
    {
        stack<int> ms;
        vector<vector<int>> pos(2,vector<int>(s+2));
        for (int y = 0; y <= s+1; y++)
        {
            while (!ms.empty() && gr[x][ms.top()] >= gr[x][y])
                ms.pop();
            pos[0][y] = ms.empty() ? 0 : ms.top();
            ms.push(y);
        }
        while (!ms.empty()) ms.pop();
        for (int y = s+1; y >= 0; y--)
        {
            while (!ms.empty() && gr[x][ms.top()] >= gr[x][y])
                ms.pop();
            pos[1][y] = ms.empty() ? s+1 : ms.top();
            ms.push(y);
        }
        for (int y = 0; y <= s+1; y++)
            ma = max(ma, (pos[1][y]-pos[0][y])*(gr[x][y]+1));
    }
    printf("%i\n", ma);
}
