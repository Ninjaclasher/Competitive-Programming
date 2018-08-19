#include <bits/stdc++.h>

using namespace std;

int find_subset(int l, int u, int w[], int n, int result[])
{
    vector<pair<long long,int>> arr(n);
    for (int x = 0; x < n; x++)
        arr[x] = {w[x], x};
    sort(arr.begin(), arr.end());
    for (int x = 1; x < n; x++)
        arr[x].first += arr[x-1].first;
    for (int x = 0, y = 0; x < n; x++)
    {
        while (y < n && arr[y].first - (x ? arr[x-1].first : 0) < l)
            y++;
        if (y == n)
            return 0;
        long long v = arr[y].first - (x ? arr[x-1].first : 0);
        if (l <= v && v <= u)
        {
            for (int z = 0; z < y-x+1; z++)
                result[z] = arr[x+z].second;
            return y-x+1;
        }
    }
    return 0;
}
