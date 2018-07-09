#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int mix = INT_MAX, maxx = -INT_MAX, miy = INT_MAX, may = -INT_MAX, n, x, y;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i%i", &x, &y);
        mix = min(mix, x), maxx = max(maxx, x);
        miy = min(miy, y), may = max(may, y);
    }
    printf("%i", (maxx-mix)*(may-miy));
    return 0;
}
