#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long mod_pow(long long base, long long exp, long long MOD)
{
    long long ret = 1;
    for (base %= MOD; exp; exp >>= 1, base = base*base%MOD)
        if (exp &1)
            ret = ret*base%MOD;
    return ret;
}

long long mod_mult(long long x, long long y, long long MOD)
{
    return x%MOD*y%MOD;
}

long long inv(long long x, long long MOD)
{
    return mod_pow(x, MOD-2, MOD);
}

long long mod_div_prime(long long x, long long y, long long MOD)
{
    return x*inv(y, MOD)%MOD;
}

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    --k;
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    long long curFac = 1;
    long long ans = 0;
    for (int x = k; x < n; x++)
    {
        ans += curFac * arr[x];
        ans %= MOD;
        curFac *= x+1;
        curFac %= MOD;
        curFac = mod_div_prime(curFac, x-k+1, MOD);
    }
    cout<<ans<<endl;
}
