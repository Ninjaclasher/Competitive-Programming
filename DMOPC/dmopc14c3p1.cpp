#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, d;
    scanf("%lli%lli%lli", &n, &k, &d);
    while (d--)
        n *= k;
    printf("%lli\n", n);
}
