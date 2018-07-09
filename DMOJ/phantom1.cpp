#include <bits/stdc++.h>

using namespace std;

bool isPrime(int a)
{
    for (int x = 2; x < sqrt(a)+1; x++)
        if (!(a%x))
            return false;
    return true;
}

int main() 
{
    int n, a, b, t;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i%i", &a, &b);
        t = 0;
        while (a < b)
            t += isPrime(a++);
        printf("%i\n", t);
    }
    return 0;
}
