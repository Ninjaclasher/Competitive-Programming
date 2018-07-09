#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a, b, day = 0, cost = INT_MAX;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        if (b > day)
            day = b, cost = a;
        else if (b == day)
            cost = min(cost, a);
    }
    printf("%i %i", cost, day);
    return 0;
}
