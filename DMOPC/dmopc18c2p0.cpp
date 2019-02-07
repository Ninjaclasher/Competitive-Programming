#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, r;
    scanf("%i%i%i", &n, &a, &r);
    int c = min(n, r/a);
    printf("%i\n", c);
}
