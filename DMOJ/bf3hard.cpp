#include <bits/stdc++.h>

using namespace std;

unsigned long long multiply (unsigned long long x, unsigned long long y, unsigned long long mod)
{
    unsigned long long prod; 
    for (prod = 0, x %= mod; y; x = (x*2) % mod, y /= 2)
        if (y % 2) prod = (prod+x) % mod;
    return prod;
}

unsigned long long pow (unsigned long long base, unsigned long long exp, unsigned long long mod)
{
    unsigned long long ret = 1;
    for (base %= mod; exp; exp /= 2, base = multiply (base, base, mod))
        if (exp % 2) ret = multiply (ret, base, mod);
    return ret;
}

bool prime(unsigned long long n)
{
    if (n == 2) return true;
    if (n < 2 || !(n % 2)) return false;
    int t = 0; 
    unsigned long long u = n-1;
    while (!(u % 2)) t++, u/=2;
    for (int x = 0; x < 4; x++)
    {
        unsigned long long q = pow (rand()%(n-1)+1, u, n);
        for (int y = 0; y < t; y++)
        {
            unsigned long long w = multiply (q, q, n);
            if (w == 1 && q != 1 && q != n-1) return false;
            q = w;
        }
        if (q != 1) return false;
    }
    return true;
}

int main()
{
    unsigned long long n;
    scanf("%llu", &n);
    while (!prime(n++));
    printf("%llu", n-1);
}
