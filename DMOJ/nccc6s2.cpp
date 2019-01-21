#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, mi = INT_MAX, ma = INT_MIN;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            scanf("%i", &a);
            if (a != x * n + y + 1)
                mi = min(mi, x), ma = max(ma, x);
        }
    }
    printf("%i\n", ma-mi+1);
}
