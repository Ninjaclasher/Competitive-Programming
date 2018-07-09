#include <bits/stdc++.h>

using namespace std;

short aa[10005][10005];

int main()
{
    int n, m, t, a, b, ma = -1;
    scanf("%i%i%i", &n, &m, &t);
    while (t--)
    {
        scanf("%i%i", &a, &b);
        if (a)
            aa[a-1][b] = 1;
    }
    for (int x = n-1; x >= 0; x--)
        for (int y = 0; y <= m; y++)
            aa[x][y] = (aa[x][y] ? 1 : aa[x+1][y]+1);
    for (int x = 0; x < n; x++)
    {
        stack<int> ms;
        vector<vector<int>> pos(2,vector<int>(m+1));
        for (int y = 0; y <= m; y++)
        {
            while (!ms.empty() && aa[x][ms.top()] >= aa[x][y])
                ms.pop();
            pos[0][y] = ms.empty() ? 0 : ms.top();
            ms.push(y);
        }
        while (!ms.empty()) ms.pop();
        for (int y = m; y >= 0; y--)
        {
            while (!ms.empty() && aa[x][ms.top()] >= aa[x][y])
                ms.pop();
            pos[1][y] = ms.empty() ? m : ms.top();
            ms.push(y);
        }
        for (int y = 0; y <= m; y++)
            ma = max(ma, (pos[1][y]-pos[0][y])*aa[x][y]);
    }
    printf("%i\n", ma);
}
