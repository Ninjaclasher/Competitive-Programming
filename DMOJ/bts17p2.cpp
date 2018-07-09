#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int g, e, p;
    double pp = 1;
    scanf("%i", &g);
    while (g--)
    {
        scanf("%i%i", &e, &p);
        pp *= (double)(p-e)/(double)p;
    }
    printf("%f", pp);
    return 0;
}
