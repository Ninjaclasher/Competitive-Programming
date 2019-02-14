#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y;
    scanf("%lli%lli", &x, &y);
    x *= y;
    printf("%lli.%i\n", x/2, x%2 ? 5 : 0);
}
