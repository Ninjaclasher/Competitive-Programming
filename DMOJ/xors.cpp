#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    int a;
    scanf("%i", &n);
    long long mi = 0, ma = 0;
    while (n--)
    {
        scanf("%i", &a);
        mi ^= a;
        ma += a;
    }
    printf("%lli\n", ma - mi);
    return 0;
}
