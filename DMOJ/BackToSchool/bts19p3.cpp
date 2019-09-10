#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    int m;
    scanf("%lli%i", &n, &m);
    assert(1 <= n && n <= 1000000000000000000L);
    assert(1 <= m && m <= 100);
    while (n & (n-1))
        n += n&-n;
    printf("%i\n", (__builtin_ctzll(n) + m-1) / m);
}
