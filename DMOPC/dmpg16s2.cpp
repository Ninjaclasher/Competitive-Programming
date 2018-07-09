#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, z = 0;
    int k, d;
    scanf("%lli%i%i", &n, &k, &d);
    for (int x = 0; x < d; x++)
    {
        z += n % k;
        n /= k;
    }
    printf("%lli", z+n);
    return 0;
}
