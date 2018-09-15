#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, b, a;
    scanf("%lli%lli%lli", &n, &b, &a);
    if (!b)
        return 0 * printf("%lli\n", n*a);
    long long x = (b*n-a)/(2*b); 
    printf("%lli\n", max((a+b*x)*(n-x), (a+b*(x+1))*(n-(x+1))));
}
