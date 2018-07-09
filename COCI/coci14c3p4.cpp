#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<int,int>> aa (n);
    vector<vector<int>> a(652, vector<int> (652)), b(652, vector<int> (652)), c(652, vector<int> (652));
    for (auto &x : aa)
    {
        scanf("%i%i", &x.first, &x.second);
        c[x.first][x.second]++;
        a[x.first][x.second]++;
        b[651-x.first][651-x.second]++;
    }
    for (int x = 0; x < a.size(); x++)
        for (int y = 1; y < a[0].size(); y++)
            a[x][y] += a[x][y-1],
            b[x][y] += b[x][y-1];
    for (int x = 1; x < a.size(); x++)
        for (int y = 0; y < a[0].size(); y++)
            a[x][y] += a[x-1][y],
            b[x][y] += b[x-1][y];
    for (auto &x : aa)
        printf("%i %i\n", b[650-x.first][650-x.second]+1, n - (x.first && x.second ? a[x.first-1][x.second-1] : 0) - (x.first == 650 ? c[0][x.second] : 0) - (x.second == 650 ? c[x.first][0] : 0));
}
