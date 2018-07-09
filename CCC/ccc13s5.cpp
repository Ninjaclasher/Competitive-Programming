#include <bits/stdc++.h>

int main()
{
    int n, cost = 0;
    scanf("%i", &n);
    while (n > 1)
    {
        int a = n, b = 1;
        for (int x = 2; x <= sqrt(n); x++)
        {
            if (!(n % x))
            {
                a = x, b = n / x;
                break;
            }
        }
        cost+=a-1;
        n-=b;
    }

    printf("%i\n", cost);
    return 0;
}
