#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, d, a, mi = INT_MAX;
    scanf("%i%i", &n, &d);
    while (n--)
    {
        scanf("%i", &a);
        if (d/a == (double)d/a) 
            mi = min(mi, abs(d/a));
    }
    if (mi == INT_MAX) printf("This is not the best time for a trip.\n");
    else printf("%i\n", mi);
    return 0;
}
