#include <bits/stdc++.h>

using namespace std;

int main()
{
    bitset<1000000> prime;
    int n, a, b;
    scanf("%i", &n);
    while (n--)
    {
        prime.reset();
        scanf("%i%i", &a, &b);
        int s = 0;
        for (int x = 2; x < b; x++)
        {
            if (!prime[x])
            {
                if (x >= a)
                    s++;
                if (x*x < b)
                    for (int y = x*2; y < b; y += x)
                        prime.set(y);
            }
        }
        printf("%i\n", s);
    }
    return 0;
}
