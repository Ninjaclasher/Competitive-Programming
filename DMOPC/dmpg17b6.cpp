#include <bits/stdc++.h>

using namespace std;

int main() 
{
    long long n, a;
    double c = 0;
    scanf("%lli", &n);
    while (n--)
    {
        scanf("%lli", &a);
        c += log2(a);
    }
    printf("%i", (int)c+1);
    return 0;
}
