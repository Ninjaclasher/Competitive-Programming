#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    for (int x = 0; x < n; x++, printf("\n"))
        for (int y = 0; y < m; y++)
            printf("%i ", ((x^(x>>1)) << 10) | (y^(y>>1)));
}
