#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    long long mi = LONG_MIN, mix = 0, miy = 0;
    for (int x = 0; x < n; x++)
    {
        long long a, b;
        scanf("%lli%lli", &a, &b);
        if (a*a+b*b > mi)
            mi = a*a+b*b, mix = a, miy = b;
    }
    printf("%lli %lli\n", mix, miy);
}
