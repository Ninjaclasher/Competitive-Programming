#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, aa = 0;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        aa += a;
    }
    printf("%.1lf\n", (double)aa / n);
}
