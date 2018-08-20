#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long r;
    for (scanf("%lli", &r); r; scanf("%lli", &r))
    {
        long long tot = 0;
        for (long long x = 1; x <= r; x++)
            tot += (long long)sqrt(r*r-x*x)+1;
        printf("%lli\n", 4*tot+1);
    }
}

