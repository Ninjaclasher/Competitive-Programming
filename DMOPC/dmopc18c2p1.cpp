#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p;
    scanf("%i", &p);
    int mix = INT_MAX, maxx = INT_MIN, miy = INT_MAX, may = INT_MIN;
    while (p--)
    {
        int x, y;
        scanf("%i%i", &x, &y);
        mix = min(mix, x);
        maxx = max(maxx, x);
        miy = min(miy, y);
        may = max(may, y);
    }
    printf("%i\n", 2 * (maxx - mix + may - miy));
}
