#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int h, m;
    scanf("%i%i", &h, &m);
    int c = 1;
    while (-6*pow(c,4) + h*pow(c,3) + 2*c*c + c > 0 && ++c <= m);
    if (c > m)
        printf("The balloon does not touch ground in the given time.");
    else
        printf("The balloon first touches ground at hour: \n%i", c);
    return 0;
}
