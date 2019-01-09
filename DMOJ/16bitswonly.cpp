#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        long long a, b, p;
        scanf("%lli%lli%lli", &a, &b, &p);
        if (a*b == p)
            printf("POSSIBLE DOUBLE SIGMA\n");
        else
            printf("16 BIT S/W ONLY\n");
    }
}
