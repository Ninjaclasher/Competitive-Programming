#include <bits/stdc++.h>

using namespace std;

long long pow (long long base, long long exp, long long mod)
{
    long long ret = 1;
    for (; exp; exp >>= 1, base = (base*base)%mod)
        if (exp & 1) ret = (ret*base)%mod;
    return ret;
}

int main() 
{
    unsigned long long n;
    scanf("%llu", &n);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    long long a = pow(2,n-2,1000000013LL), b = pow(2, n/2-1, 1000000013LL);
    if (n%4 == 2) 
        b = 0;
    else if (n%8 == 3 || n%8 == 4 || n%8 == 5)
        b = -b;
    printf("%lli", (1000000013LL+a+b)%1000000013LL);
    return 0;
}
