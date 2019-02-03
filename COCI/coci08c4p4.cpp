#include <bits/stdc++.h>

using namespace std;

int dp[512][512][10];
int psa[512][512];
int grid[512][512][10];

int get(int x, int y)
{
    return x < 0 || y < 0 ? 0 : psa[x][y];
}

int query(int x1, int y1, int x2, int y2)
{
    return get(x2, y2) - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
}

int query2(int x1, int y1, int x2, int y2)
{
    return (x2-x1+1) * (y2-y1+1) - query(x1, y1, x2, y2);
}

struct bound
{
    int x1, y1, x2, y2, i;
    friend bool operator<(bound a, bound b)
    {
        return a.i < b.i;
    }
};

int solve(int x, int y, int len)
{
    int &cur = dp[x][y][len];
    if (~cur)
        return cur;
    if (len == 0)
    {
        grid[x][y][0] = query(x, y, x, y);
        return cur = 0;
    }
    int mx = x + (1<<(len-1));
    int my = y + (1<<(len-1));
    int fx = x + (1<<len);
    int fy = y + (1<<len);
    --fx;
    --fy;
    vector<bound> arr = {
        {x, y, mx-1, my-1, 0},
        {x, my, mx-1, fy, 1},
        {mx, y, fx, my-1, 2},
        {mx, my, fx, fy, 3},
    };
    cur = INT_MAX;
    do
    {
        int t = 0;
        int i = 0, j = 1;
        t += query(arr[i].x1, arr[i].y1, arr[i].x2, arr[i].y2);
        t += query2(arr[j].x1, arr[j].y1, arr[j].x2, arr[j].y2);
        for (int z = 2; z < 4; z++)
            t += solve(arr[z].x1, arr[z].y1, len-1);
        if (t < cur)
        {
            cur = t;
            for (int xx = arr[i].x1; xx <= arr[i].x2; xx++)
                for (int yy = arr[i].y1; yy <= arr[i].y2; yy++)
                    grid[xx][yy][len] = 0;
            for (int xx = arr[j].x1; xx <= arr[j].x2; xx++)
                for (int yy = arr[j].y1; yy <= arr[j].y2; yy++)
                    grid[xx][yy][len] = 1;
            for (int z = 2; z < 4; z++)
            {
                for (int xx = arr[z].x1; xx <= arr[z].x2; xx++)
                    for (int yy = arr[z].y1; yy <= arr[z].y2; yy++)
                        grid[xx][yy][len] = grid[xx][yy][len-1];
            }
        }
    }
    while (next_permutation(arr.begin(), arr.end()));
    return cur;
}

int main()
{
    int n;
    scanf("%i", &n);
    int k = 0;
    for (; k < 10; k++)
        if (n>>k&1)
            break;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            char c;
            scanf(" %c", &c);
            psa[x][y] = c-'0';
            if (y)
                psa[x][y] += psa[x][y-1];
            if (x)
                psa[x][y] += psa[x-1][y];
            if (x && y)
                psa[x][y] -= psa[x-1][y-1];
        }
    }
    memset(dp, -1, sizeof dp);
    printf("%i\n", solve(0, 0, k));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            printf("%i", grid[x][y][k]);
        printf("\n");
    }
}
