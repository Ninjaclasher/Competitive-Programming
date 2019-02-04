#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a;
    scanf("%i%i", &n, &m);
    int ans = 0;
    while (m--)
    {
        scanf("%i", &a);
        ans += (a >= n);
    }
    printf("%i\n", ans);
}
