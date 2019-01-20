#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

long long mod_pow(long long base, long long exp)
{
    long long ret = 1;
    for (base %= MOD; exp; exp >>= 1, base = base*base%MOD)
        if (exp &1)
            ret = ret*base%MOD;
    return ret;
}

long long inv(long long x)
{
    return mod_pow(x, MOD-2);
}

long long p, np;
int n;

long long dp[2][1005][1005];
long long arr[1005][1005];

long long solve(int dir, int x, int y)
{
    long long &cur = dp[dir][x][y];
    if (~cur)
        return cur;
    cur = arr[x][y];
    if (x == n-1 && y == n-1)
        return cur;
    //right
    if (dir == 0)
    {
        if (y == n-1)
            cur += solve(1, x+1, y);
        else
            cur += (np * solve(0, x, y+1)%MOD + p * solve(1, x, y+1)%MOD)%MOD;
    }
    else
    {
        if (x == n-1)
            cur += solve(0, x, y+1);
        else
            cur += (np * solve(1, x+1, y)%MOD + p * solve(0, x+1, y)%MOD)%MOD;
    }
    return cur %= MOD;
}

int main()
{
    memset(dp, -1, sizeof dp);
    int a, b;
    scanf("%i%i", &a, &b);
    p = a * inv(b) % MOD;
    np = ((1-p)%MOD + MOD)%MOD;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            scanf("%lli", &arr[x][y]);
    printf("%lli\n", (p * solve(0, 0, 0)%MOD + np * solve(1, 0, 0)%MOD) % MOD);
}

