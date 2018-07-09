#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    long long ma = 0;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i%i", &a, &b);
        if (b > 0)
            ma += a;
    }
    printf("%lli", ma);
}
