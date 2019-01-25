#include <bits/stdc++.h>

using namespace std;

long long roundd(long double a)
{
    if (abs(a-(long long)a-0.5) <= 1e-14)
        return (long long)a + (((long long)a)&1 ? 1 : 0);
    else
        return round(a);
}

int main()
{
    int n, a;
    scanf("%i", &n);
    long double minr = 0, maxr = 0;
    while (n--)
    {
        scanf("%i", &a);
        if (a&1)
        {
            minr += (long double)a-(long double)0.499995L;
            maxr += (long double)a+(long double)0.499995L;
        }
        else
        {
            minr += (long double)a-0.5L;
            maxr += (long double)a+0.5L;
        }
    }
    printf("%lli\n", roundd(minr));
    printf("%lli\n", roundd(maxr));
}

