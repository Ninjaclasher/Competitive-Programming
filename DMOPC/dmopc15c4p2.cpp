#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int h, m, n;
    scanf("%i%i%i", &h, &m, &n);
    h += n/60;
    h %= 24;
    m += n%60;
    if (m >= 60)
        m -= 60, h++, h %= 24;
    printf("%i %i", h, m);
    return 0;
}
