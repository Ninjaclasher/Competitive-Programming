#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, n, r;
    scanf("%i%i%i", &p, &n, &r);
    int t = 0;
    for (int s = 0; s <= p; t++)
    {
        s += n;
        n *= r;
    }
    printf("%i\n", t - 1);
}
