#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        int ans = 0;
        for (; a%4 && a <= b; a++)
            ans ^= a;
        for (; b%4 != 3 && a <= b; b--)
            ans ^= b;
        printf("%i\n", ans);
    }
}
