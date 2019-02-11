#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long ans = 0;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        ans += n-1;
    printf("%lli\n", ans);
}
