#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, maxx = INT_MIN, mixx = INT_MAX, mayy = INT_MIN, miyy = INT_MAX, a, b;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i%i", &a, &b);
        maxx = max(a, maxx);
        mixx = min(a, mixx);
        mayy = max(b, mayy);
        miyy = min(b, miyy);
    }
    int l = max(maxx-mixx, mayy-miyy);
    printf("%i\n", l*l);
}
