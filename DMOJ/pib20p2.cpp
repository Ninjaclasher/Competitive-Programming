#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    scanf("%lli", &t);
    long long ans = t * 2;
    for (int x = 0; x < 100; x++)
        ans = (t + ans / 7) * 2;
    for (int x = 100; x >= 0; x--)
        if ((ans + x) / 2 - (ans + x) / 7 <= t)
            ans += x;
    printf("%lli\n", ans);
}
