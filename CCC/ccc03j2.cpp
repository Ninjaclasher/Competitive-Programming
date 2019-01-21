#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    for (scanf("%i", &n); n; scanf("%i", &n))
    {
        int mi = 0;
        for (int x = 1; x*x <= n; x++)
            if (n%x == 0)
                mi = x;
        printf("Minimum perimeter is %i with dimensions %i x %i\n", 2 * (n/mi + mi), mi, n/mi);
    }
}
