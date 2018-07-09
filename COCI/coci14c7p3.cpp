#include <bits/stdc++.h>

using namespace std;

int n, dp[3][150001];

vector<vector<int>> task (3, vector<int> (150001, INT_MAX));

int fillDP()
{
    memset(dp, 1000000, sizeof (dp));
    dp[0][0] = task[0][0];
    for (int x = 1; x < n; x++)
    {
        dp[0][x] = dp[0][x-1] + task[0][x];
        dp[1][x] = min(dp[0][x-1] + task[1][x], dp[1][x-1] + task[1][x]);
        dp[2][x] = min(dp[1][x-1] + task[2][x], dp[2][x-1] + task[2][x]);        
    }
    return dp[2][n-1];
}


int main()
{
    scanf("%i", &n);
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < n; x++)
            scanf("%i", &task[y][x]);
    int mi = fillDP();
    swap(task[1], task[2]);
    mi = min (mi, fillDP());
    swap(task[0], task[1]);
    mi = min (mi, fillDP());
    swap(task[0], task[2]);
    mi = min (mi, fillDP());
    swap(task[1], task[2]);
    mi = min (mi, fillDP());
    swap(task[0], task[1]);
    mi = min (mi, fillDP());
    printf("%i", mi);
}
