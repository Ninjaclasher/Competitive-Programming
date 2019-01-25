#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lli", &n);
    long long lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + hi >> 1;
        if ((n + mid - 1) * (n - mid) < n*(n-1)/2)
            hi = --mid;
        else
            lo = ++mid;
    }
    printf("%lli\n", n - lo + 1);
}
