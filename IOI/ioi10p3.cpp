#include <bits/stdc++.h>

using namespace std;

int run(int m, int R, int C, int H, int W, vector<vector<int>> &Q)
{
    vector<vector<int>> arr(R+1, vector<int>(C+1));
    for (int x = 1; x <= R; x++)
    {
        for (int y = 1; y <= C; y++)
        {
            if (m > Q[x-1][y-1])
                arr[x][y] = -1;
            else if (m < Q[x-1][y-1])
                arr[x][y] = 1;
            arr[x][y] += arr[x-1][y] + arr[x][y-1] - arr[x-1][y-1];
        }
    }
    int haszero = 0;
    for (int x = H; x <= R; x++)
    {
        for (int y = W; y <= C; y++)
        {
            int cur = arr[x][y] - arr[x-H][y] - arr[x][y-W] + arr[x-H][y-W];
            if (!cur)
                haszero = 1;
            else if (cur < 0)
                return -1;
        }
    }
    return haszero ? 0 : 1;
}

int rectangle(int R, int C, int H, int W, int Q[3001][3001])
{
    int l = 1, r = R*C;
    vector<vector<int>> arr(3001, vector<int>(3001));
    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++)
            arr[x][y] = Q[x][y];
    while (true)
    {
        int m = l+r>>1;
        int v = run(m, R, C, H, W, arr);
        if (v > 0)
            l = m+1;
        else if (v < 0)
            r = m-1;
        else
            return m;
    }
}
