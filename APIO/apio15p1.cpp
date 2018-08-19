#include <bits/stdc++.h>

using namespace std;

int n, a, b;
long long arr[2003], psa[2003];
int dp[2003][2003];
long long ans = 0;

static inline __attribute__((always_inline)) bool valid(long long v, int bit)
{
    return (((v>>bit|ans)>>1<<1) == ans) && !(v>>bit&1);
}

void run(int bit)
{
    memset(dp, 0, sizeof(dp));
    if (a > 1)
    {
        for (int x = 1; x <= n; x++)
        {
            dp[x][1] = valid(psa[x], bit);
            for (int y = 2; y <= x; y++)
                for (int z = 1; z < x; z++)
                    if (dp[z][y-1])
                        dp[x][y] |= valid(psa[x]-psa[z], bit);
        }
        int ze = 0;
        for (int x = a; x <= b; x++)
            ze |= dp[n][x];
        ans |= !ze;
    }
    else
    {
        for (int x = 1; x <= n; x++)
        {
            dp[0][x] = INT_MAX;
            for (int y = 0; y < x; y++)
                if (dp[0][y] < INT_MAX && valid(psa[x]-psa[y], bit))
                    dp[0][x] = min(dp[0][x], dp[0][y]+1);
        }
        ans |= (dp[0][n] > b);
    }
    ans <<= 1;
}

int main()
{
    scanf("%i%i%i", &n, &a, &b);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]), psa[x] = psa[x-1] + arr[x];
    for (int x = 40; x >= 0; x--)
        run(x);
    printf("%lli\n", ans>>1);
}
