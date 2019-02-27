#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<bool> sieve(2000001, true);
    sieve[0] = sieve[1] = 0;
    for (long long x = 2; x < sieve.size(); x++)
    {
        if (sieve[x])
            for (long long y = x*x; y < sieve.size(); y += x)
                sieve[y] = 0;
    }
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        scanf("%i", &n);
        for (int x = 0; x < n; x++)
        {
            if (sieve[n-x] && sieve[n+x])
            {
                printf("%i %i\n", n-x, n+x);
                break;
            }
        }
    }
}

