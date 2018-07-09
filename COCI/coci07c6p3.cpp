#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, gcd = 0, p = 0, c = 0;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &c);
        if (x) gcd = __gcd(gcd, abs(c-p));
        p = c;
    }
    for (int x = 2; x <= sqrt(gcd); x++)
    {
        if (!(gcd%x))
        {
            printf("%i ", x);
            if (x !=  gcd/x)
                printf("%i ", gcd/x);
        }
    }
    printf("%i", gcd);
}
