#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

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

long long mod_div_prime(long long x, long long y)
{
    return x*inv(y)%MOD;
}

vector<long long> ffff(int oo)
{
    vector<long long> arr(oo+1);
    arr[0] = 1;
    for (int x = 1; x < arr.size(); x++)
        arr[x] = mod_div_prime((arr[x-1] * (oo - x + 1) % MOD), x);
    for (int x = 1; x < arr.size(); x++)
    {
        arr[x] += arr[x-1];
        arr[x] %= MOD;
    }
    return arr;
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<int,int>> arr(n);
    long long o3 = 0, o2 = 0, t3 = 0; 
    for (auto &x : arr)
    {
        scanf("%i%i", &x.first, &x.second);
        if (x.first > x.second)
            swap(x.first, x.second);
        if (x.first == 1 && x.second == 2)
            o2++;
        else if (x.first == 1 && x.second == 3)
            o3++;
        else
            t3++;
    }
    vector<long long> ao3 = ffff(o3);
    vector<long long> ao2 = ffff(o2);
    vector<long long> at3 = ffff(t3);
    long long ans = 0;
    for (long long ii = 1; ii <= min(o2, o3); ii++)
    {
        long long a = (ao2.back() - ao2[ii] + MOD) % MOD * (ao3[ii] - ao3[ii-1] + MOD) % MOD;
        long long b = (ao3.back() - ao3[ii] + MOD) % MOD * (ao2[ii] - ao2[ii-1] + MOD) % MOD;
        long long c = a+b + (ao2[ii] - ao2[ii-1]) * (ao3[ii] - ao3[ii-1]) % MOD;
        c %= MOD;
        c += MOD;
        c %= MOD;
        c *= at3[min(ii-1, t3)];
        c %= MOD;
        ans += c;
        ans %= MOD;
    }
    cout << ans % MOD << endl;
}
