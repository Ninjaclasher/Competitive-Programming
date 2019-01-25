#include <bits/stdc++.h>

using namespace std;

struct pp
{
    int v, s, t;
    friend bool operator<(pp &a, pp &b)
    {
        return a.t < b.t;
    }
};

int dp[2][1005];

int main()
{
    int n;
    scanf("%i", &n);
    vector<pp> arr(n);
    for (auto &x : arr)
        scanf("%i%i%i", &x.v, &x.s, &x.t);
    sort(arr.begin(), arr.end());
    for (int x = 0; x < n; x++)
    {
        int c = x&1;
        for (int y = 0; y < arr[x].s; y++)
            dp[c][y] = dp[c^1][y];
        for (int y = arr[x].t+1; y < 1005; y++)
            dp[c][y] = dp[c^1][y];
        for (int y = arr[x].s; y <= arr[x].t; y++)
            dp[c][y] = max(dp[c^1][y], dp[c^1][y-arr[x].s] + arr[x].v);
    }
    int ma = 0;
    for (int x = 0; x < 1005; x++)
        ma = max(ma, dp[n&1^1][x]);
    printf("%i\n", ma);
}


