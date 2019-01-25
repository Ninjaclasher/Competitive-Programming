#include <bits/stdc++.h>

using namespace std;

int dp[2][1<<20];

static inline __attribute__((always_inline)) bool chk(int x)
{
    return !((x & (x>>1)) || (x & (x>>2)));
}

const int MOD = 1000000007;

int main()
{
    vector<int> valid;
    int r, c;
    scanf("%i%i", &r, &c);
    for (int x = 0; x < (1<<(c-2)); x++)
        if (chk(x))
            valid.push_back(x);
    for (auto x : valid)
        dp[0][x] = 1;
    for (int x = 1; x < r-1; x++)
    {
        memset(dp[x&1], 0, 1<<22);
        for (auto i : valid)
            for (auto j : valid)
                if (!(i&(j|(j>>1)|(j<<1))))
                    dp[x&1][i] = (dp[x&1][i] + dp[(x&1)^1][j]) % MOD;
    }
    long long s = 0;
    for (int x = 0; x < (1<<20); x++)
        s += dp[r&1][x];
    printf("%lli\n", (s-1+MOD)%MOD);
}
