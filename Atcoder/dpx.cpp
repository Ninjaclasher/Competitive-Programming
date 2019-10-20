#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int MAXW = 20005;

long long dp[MAXN][MAXW];

struct block
{
    int w, s, v;

    friend bool operator<(block a, block b)
    {
        return a.s + a.w < b.s + b.w;
    }
};

int main()
{
    int n;
    scanf("%i", &n);
    vector<block> arr(n+1);
    for (int x = 1; x <= n; x++)
        scanf("%i%i%i", &arr[x].w, &arr[x].s, &arr[x].v);
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (int x = 1; x <= n; x++)
    {
        int w = arr[x].w, s = arr[x].s, v = arr[x].v;
        for (int y = 0; y < MAXW; y++)
            dp[x][y] = dp[x-1][y];
        for (int y = 0; y <= s; y++)
            if (y + w < MAXW)
                dp[x][y + w] = max(dp[x][y + w], dp[x-1][y] + v);
        for (int y = 0; y < MAXW; y++)
            ans = max(ans, dp[x][y]);
    }
    printf("%lli\n", ans);
}
