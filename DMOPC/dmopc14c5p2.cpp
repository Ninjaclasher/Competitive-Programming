#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    scanf("%i", &n);
    int ma = 0;
    while (n--)
    {
        scanf("%i%i", &a, &b);
        ma = max(ma, b-a);
    }
    printf("%i\n", ma);
}
