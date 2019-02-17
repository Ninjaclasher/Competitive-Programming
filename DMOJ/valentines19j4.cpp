#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> cannot(301, vector<bool>(301));

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    long long ans = 0;
    vector<pair<int,int>> arr(301);
    for (int x = 1; x <= n; x++)
        scanf("%i%i", &arr[x].first, &arr[x].second);
    while (m--)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        cannot[a][b] = cannot[b][a] = true;
    }
    for (int x = 1; x <= n; x++)
        cannot[x][x] = true;
    for (int x = 1; x <= n; x++)
    {
        ans = max(ans, (long long)arr[x].second);
        for (int y = 1; y <= n; y++)
        {
            if (cannot[x][y])
                continue;
            ans = max(ans, (long long)arr[x].second * arr[y].first + arr[y].second);
            for (int z = 1; z <= n; z++)
            {
                if (cannot[x][z] || cannot[y][z])
                    continue;
                long long cur = 0;
                cur += arr[x].second;
                cur *= arr[y].first;
                cur += arr[y].second;
                cur *= arr[z].first;
                cur += arr[z].second;
                ans = max(ans, cur);
            }
        }
    }
    printf("%lli\n", ans);
}
