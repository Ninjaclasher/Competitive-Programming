#include <bits/stdc++.h>

using namespace std;

int val[1000000];

int main()
{
    int n, a, b, t, m = 0;
    scanf("%i%i%i", &n, &a, &b);
    for (int x = 0; x < a; x++)
    {
        scanf("%i", &t);
        val[t]++;
    }
    for (int x = 0; x < b; x++)
    {
        scanf("%i", &t);
        val[t]++;
    }
    for (int x = 0; x < 1000000; x++)
        if (val[x] == 2)
            m++;
    printf("%i", n-m);
    return 0;
}
