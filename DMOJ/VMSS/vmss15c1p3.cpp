#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, n;
    scanf("%i%i%i%i", &a, &b, &c, &d);
    scanf("%i", &n);
    int ans = 0;
    long long A, B, C;
    while (n--)
    {
        scanf("%lli%lli%lli", &A, &B, &C);
        if (signbit(A*a + B*b + C) != signbit(A*c + B*d + C))
            ans++;
    }
    printf("%i\n", ans);
}
