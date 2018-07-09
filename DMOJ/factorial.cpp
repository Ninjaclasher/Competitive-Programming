#include <bits/stdc++.h>

using namespace std;


int main()
{
    vector<unsigned long long> fac (34,1);
    for (unsigned long long x = 1; x < 34; x++)
        fac[x] = (fac[x-1]*x)%4294967296;
    unsigned long long n, a;
    scanf("%llu", &n);
    while (n--)
    {
        scanf("%llu", &a);
        if (a > 33) printf("0\n");
        else printf("%llu\n", fac[a]);
    }
}
