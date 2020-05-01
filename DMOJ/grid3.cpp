#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

const int MAXN = 1000005;

long long fac[MAXN], invfac[MAXN];

long long mod_pow(long long b, long long e)
{
    long long ret = 1;
    for (b %= MOD; e; b = b * b % MOD, e >>= 1)
        if (e&1)
            ret = ret * b % MOD;
    return ret;
}

long long choose(vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    assert(sum < MAXN);
    long long ret = fac[sum];
    for (auto &x : arr)
        ret = ret * invfac[x] % MOD;
    return ret;
}

int main()
{
    fac[0] = 1;
    for (int x = 1; x < MAXN; x++)
        fac[x] = fac[x-1] * x % MOD;
    for (int x = 0; x < MAXN; x++)
        invfac[x] = mod_pow(fac[x], MOD-2);
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int q;
    scanf("%i", &q);
    vector<vector<int>> qq(q, vector<int> (n));
    for (auto &x : qq)
        for (auto &y : x)
            scanf("%i", &y);
    qq.push_back(arr);
    sort(qq.begin(), qq.end(), [&](auto &a, auto &b){
        for (int x = 0; x < n; x++)
            if (a[x] > b[x]) return false;
            else if (a[x] < b[x]) return true;
        return true;
    });
    vector<long long> cache(qq.size(), -1);
    vector<int> tmp(n);
    for (int x = 0; x < qq.size(); x++)
    {
        for (int z = 0; z < n; z++)
            tmp[z] = qq[x][z] - 1;
        cache[x] = choose(tmp);
        for (int y = 0; y < x; y++)
        {
            bool fail = false;
            for (int z = 0; z < n; z++)
            {
                tmp[z] = qq[x][z] - qq[y][z];
                fail |= tmp[z] < 0;
            }
            if (!fail)
            {
                cache[x] -= choose(tmp) * cache[y];
                cache[x] = (cache[x] % MOD + MOD) % MOD;
            }
        }
    }
    printf("%lli\n", cache.back());
}
