#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;

int dp[MAXN][MAXN];

vector<int> arr(MAXN);

int solve(int l, int r)
{
    if (l == r)
        return arr[l];
    if (l+1 == r)
        return 0;
    int &cur = dp[l][r];
    if (~cur)
        return cur;
    for (int x = l+1; x < r; x++)
        cur = max(cur, solve(l, x) + arr[l] + arr[x] + arr[r] + solve(x, r));
    return cur;
}

int main()
{
    int n;
    for (scanf("%i", &n); n; scanf("%i", &n))
    {
        memset(dp, -1, sizeof dp);
        for (int x = 0; x < n; x++)
            scanf("%i", &arr[x]);
        printf("%i\n", solve(0, n-1));
    }
}
