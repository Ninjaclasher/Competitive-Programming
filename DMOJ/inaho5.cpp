#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    unsigned long long ans = 0;
    long long a;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%lli", &a);
        ans += -a;
    }
    if (!ans)
        printf("0\n");
    else
        printf("-%llu\n", ans);
}
