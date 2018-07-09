#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    n%=m;
    if (n < 0) n += m;
    printf("%i", n);
}
