#include <bits/stdc++.h>

using namespace std;

unsigned long long multiply (unsigned long long x, unsigned long long y, unsigned long long mod)
{
    unsigned long long prod = 0; 
    for (x %= mod; y; x = (x<<1) % mod, y>>=1)
        if (y&1) prod = (prod+x) % mod;
    return prod;
}

unsigned long long pow (unsigned long long base, unsigned long long exp, unsigned long long mod)
{
    unsigned long long ret = 1;
    for (base %= mod; exp; exp>>=1, base = multiply (base, base, mod))
        if (exp&1) ret = multiply (ret, base, mod);
    return ret;
}

const int prime_a[12] = {2,3,5,7, 11,13,17,19, 23,29, 31,37};
bool prime(unsigned long long n)
{
    if (n <= 2 || !(n&1))
        return n == 2;
    int t = 0; 
    unsigned long long u = n-1;
    while (!(u&1))
        t++, u >>= 1;
    for (int x = 0; x < 12 && (unsigned long long)prime_a[x] < n; x++)
    {
        int a = prime_a[x], found = 0;
        if (pow(a, u, n) == 1)
            continue;
        for (int y = 0; y < t && !found; y++)
            if (pow(a, (u<<y), n) == n-1)
                found = 1;
        if (!found)
            return false;
    }
    return true;
}

long long next_prime(long long n)
{
    while (!prime(n)) ++n;
    return n;
}

long long ppow[12];

int main()
{
    ppow[0] = 1;
    for (int x = 1; x < 12; x++)
        ppow[x] = ppow[x-1] * 10;
    int d, n;
    scanf("%i%i", &d, &n);
    long long lo = next_prime(ppow[d-1]);
    string s = to_string(n);
    long long mi = LONG_MAX;
    if (d > s.length())
        return 0 * printf("%lli%lli\n", lo, lo);
    for (int x = 0; x+d <= s.length(); x++)
    {
        int pref = x ? stoi(s.substr(0, x)) : 0;
        int suf = -1;
        if (x < d)
            pref = lo, suf = next_prime(ppow[s.length()-x-1]);
        else if (prime(pref))
        {
            suf = stoi(s.substr(x, s.length()));
            suf = max((long long)suf, ppow[s.length()-x-1]);
            suf = next_prime(suf);
            mi = min(mi, stoll(to_string(pref) + to_string(suf)));
            ++pref;
        }
        if (x >= d)
        {
            pref = next_prime(pref);
            suf = next_prime(ppow[s.length()-x-1]);
        }
        long long cur = stoll(to_string(pref) + to_string(suf));
        mi = min(mi, cur);
    }
    printf("%lli\n", mi);
}
