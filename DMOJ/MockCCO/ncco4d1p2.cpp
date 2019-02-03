#include <bits/stdc++.h>

using namespace std;

const long long MOD = 100000000;

long long dp[13][4096];

static inline __attribute__((always_inline)) bool val(int i)
{
    return (i & (i<<1)) == 0;
}

int main()
{
    int r, c, a;
    scanf("%i%i", &r, &c);
    vector<int> valid;
    for (int x = 0; x < (1<<c); x++)
        if (val(x))
            valid.push_back(x);
    vector<int> row(r);
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            scanf("%i", &a);
            row[x] = row[x]<<1|a;
        }
    }
    for (auto &x : valid)
        if ((x|row[0]) == row[0])
            dp[0][x]++;
    for (int x = 1; x < r; x++)
    {
        for (auto &y : valid)
        {
            for (auto &z : valid)
            {
                if (!(y&z) && (z|row[x]) == row[x])
                {
                    dp[x][z] += dp[x-1][y];
                    dp[x][z] %= MOD;
                }
            }
        }
    }
    long long ans = 0;
    for (auto &x : valid)
        ans += dp[r-1][x];
    printf("%lli\n", ans%MOD);
}
