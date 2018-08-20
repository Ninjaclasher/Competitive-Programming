#include <bits/stdc++.h>

using namespace std;

int reactions[5][4] = {
    {2,1,0,2},
    {1,1,1,1},
    {0,0,2,1},
    {0,3,0,0},
    {1,0,0,1},
};

int dp[32][32][32][32];

int solve(vector<int> &arr)
{
    int &cur = dp[arr[0]][arr[1]][arr[2]][arr[3]];
    if (~cur)
        return cur;
    cur = 1;
    for (auto x : reactions)
    {
        vector<int> next({arr[0]-x[0], arr[1]-x[1], arr[2]-x[2], arr[3]-x[3]});
        if (next[0] >= 0 && next[1] >= 0 && next[2] >= 0 && next[3] >= 0)
            cur &= !solve(next);
    }
    return cur;
}


int main()
{
    memset(dp, -1, sizeof(dp));
    int n = 0;
    scanf("%i", &n);
    while (n--)
    {
        vector<int> arr(4);
        for (auto &x : arr)
            scanf("%i", &x);
        printf("%s\n", solve(arr) ? "Roland" : "Patrick");
    }
}

