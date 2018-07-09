#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    scanf("%i", &n);
    long long a;
    while (n--)
    {
        scanf("%lli", &a);
        printf("%s\n", a&(a-1) ? "F" : "T");
    }
    return 0;
}
