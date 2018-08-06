#include <bits/stdc++.h>

using namespace std;

int dp[5010], pre[505][5010];

int main()
{
    memset(dp, -1, sizeof(dp));
    memset(pre, -1, sizeof(pre));
    pre[0][0] = -2;
    dp[0] = 0;
    int t, n;
    scanf("%i%i", &t, &n);
    vector<int> arr(n+1);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &arr[x]);
        for (int y = t; y >= arr[x]; y--)
            if (~dp[y-arr[x]])
                dp[y] = dp[y-arr[x]], pre[x][y] = x-1;
    }
    int i = t, j = n;
    while (!~dp[i]) --i;
    while (!~pre[j][i]) --j;
    vector<int> o(n+1);
    while (i && j)
    {
        o[j] = 1;
        int tmp = i;
        i -= arr[j];
        j = pre[j][tmp];
        while (j && !~pre[j][i]) --j;
    }
    int s[2] = {0, 0};
    for (int x = 1; x <= n; x++)
    {
        printf("%i ", s[o[x]]);
        s[o[x]] += arr[x];
    }
}
