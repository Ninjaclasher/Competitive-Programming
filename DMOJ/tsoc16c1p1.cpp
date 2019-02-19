#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    int l, a, b, f;
    while (n--)
    {
        scanf("%i%i%i%i", &l, &a, &b, &f);
        int t = abs(l-f);
        if (a <= t && t <= b)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
