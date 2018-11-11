#include <bits/stdc++.h>

using namespace std;

const int MAXN = 16;

int dp[1<<16];

int arr[MAXN];

bool losing(int msk)
{
    bool dec = true, inc = true;
    int prev = -1;
    for (int x = 0; x < MAXN; x++)
    {
        if (msk>>x&1)
        {
            if (~prev)
            {
                if (arr[x] < prev)
                    inc = false;
                else if (arr[x] > prev)
                    dec = false;
            }
            prev = arr[x];
        }
    }
    return inc || dec;
}

int solve(int msk)
{
    if (~dp[msk])
        return dp[msk];
    if (losing(msk))
        return dp[msk] = 0;
    dp[msk] = 0;
    for (int x = 0; x < MAXN; x++)
        if (msk>>x&1)
            dp[msk] |= !solve(msk^(1<<x));
    return dp[msk];
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            memset(dp, -1, sizeof dp);
            int n;
            scanf("%i", &n);
            for (int x = 0; x < n; x++)
                scanf("%i", &arr[x]);
            printf("%c", solve((1<<n)-1) ? 'A' : 'B');
        }
        printf("\n");
    }
}
