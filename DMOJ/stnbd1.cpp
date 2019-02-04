#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ma, a;
    scanf("%i", &n);
    scanf("%i", &ma);
    while (--n)
    {
        scanf("%i", &a);
        if (a >= ma)
            return 0 * printf("NO\n");
    }
    printf("YES\n");
}
