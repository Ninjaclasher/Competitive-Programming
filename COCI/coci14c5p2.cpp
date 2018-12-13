#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, s;
    scanf("%i%i", &r, &s);
    vector<vector<int>> mm(2, vector<int>(r));
    fill(mm[0].begin(), mm[0].end(), INT_MAX);
    fill(mm[1].begin(), mm[1].end(), INT_MIN);
    char c;
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < s; y++)
        {
            scanf(" %c", &c);
            if (c == 'J')
            {
                mm[0][r-x-1] = min(mm[0][r-x-1], y);
                mm[1][r-x-1] = max(mm[1][r-x-1], y);
            }
        }
    }
    int cur = 0, ma = 0;
    long long ans = 0;
    for (int x = 0; x < r; x++)
    {
        if (mm[0][x] == INT_MAX)
            continue;
        ma = x;
        if (x&1)
        {
            ans += abs(cur-mm[1][x]) + abs(mm[1][x]-mm[0][x]);
            cur =mm[0][x];
        }
        else
        {
            ans += abs(cur-mm[0][x]) + abs(mm[1][x]-mm[0][x]);
            cur = mm[1][x];
        }
    }
    printf("%lli\n", ans+ma);
}
