#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long a, GCD = 0, ma = 0;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%lli", &a);
        GCD = __gcd(GCD, a);
    }
    for (long long x = 2; x <= sqrt(GCD); x++)
    {
        while (!(GCD%x))
            GCD /= x, ma = x;
    }
    ma = max(ma, GCD);
    if (ma < 2)
        printf("DNE\n");
    else
        printf("%lli\n", ma);
}
