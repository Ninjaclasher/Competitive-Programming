#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, s, sum = 0, a;
    scanf("%i", &i);
    for (int x = 0; x < i; x++)
    {
        scanf("%i", &a);
        sum += a;
    }
    scanf("%i", &s);
    for (int x = 0; x < s; x++)
    {
        scanf("%i", &a);
        sum += a;
        printf("%.10Lf\n", (long double)sum / (i+x+1));
    }
}
