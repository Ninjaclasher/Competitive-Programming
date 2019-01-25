#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lli", &n);
    if (n > 140)
        printf("0.438283\n0.360592\n");
    else if (!n)
        printf("1\n0\n");
    else
    {
        complex<long double> base(0, 1), exponent(0, 1);
        for (int x = 1; x < n; x++)
            exponent = pow(base, exponent);
        printf("%Lf\n%Lf\n", exponent.real(), exponent.imag());
    }

}
