#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%i%i", &a, &b);
    if (a%b == 0)
        printf("%i\n", a/b);
    else
    {
        int g = __gcd(a, b);
        a /= g;
        b /= g;
        if (a > b)
            printf("%i %i/%i\n", a/b, a%b, b);
        else
            printf("%i/%i\n", a, b);
    }
}

