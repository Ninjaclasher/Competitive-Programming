#include <stdio.h>

const unsigned long long mod = 666013;

int tmpa[1000001], tmpb[1000001];

int main()
{
    int n, q, a;
    scanf("%i%i", &n, &q);
    for (int x = 0, pow10 = 1, pow3 = 1; x <= n; x++, pow10*=10, pow10%= mod, pow3*=3, pow3%=mod)
        tmpa[x] = 9*pow10%mod, tmpb[x] = 2*pow3%mod;
    while (q--)
    {
        scanf("%i", &a);
        int b = (a-1)/2;
        printf("%llu\n", (20*mod + tmpa[a-1] - (tmpa[b] + tmpb[a-1] - tmpb[b])) % mod);    
    }
}
