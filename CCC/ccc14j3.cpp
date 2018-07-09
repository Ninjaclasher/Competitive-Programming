#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a, b, aa = 100, bb = 100;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i%i", &a, &b);
        if (a > b)
            bb -= a;
        else if (a < b)
            aa -= b;
    }
    printf("%i\n%i\n", aa, bb);
    return 0;
}
