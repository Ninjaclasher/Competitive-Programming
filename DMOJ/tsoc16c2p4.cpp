#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<int> primes;
    vector<bool> sieve(n+5, true);
    for (int x = 2; x <= n; x++)
    {
        if (sieve[x])
        {
            primes.push_back(x-2);
            for (int y = x*x; y <= n; y += x)
                sieve[y] = false;
        }
    }
    sieve[0] = sieve[1] = false;
    
    vector<int> p(m);
    for (auto &x : p)
        scanf("%i", &x);

    vector<bool> vis(n+1);
    int sum = 0;
    for (auto &x : p)
        sum += x*2;
    vis[sum] = true;
    for (int x = sum; x <= n; x++)
    {
        if (vis[x])
        {
            if (sieve[x])
                return 0 * printf("its primetime\n");
            for (auto &y : p)
            {
                for (auto &z : primes)
                {
                    if (y*z+x <= n)
                        vis[y*z+x] = true;
                    else
                        break;
                }
            }
        }
    }
    printf("not primetime\n");
}
