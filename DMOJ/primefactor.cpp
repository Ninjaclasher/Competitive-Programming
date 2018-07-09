#include <bits/stdc++.h>

using namespace std;

void prime(int n)
{
    int root = ceil(sqrt(n))+3;
    for (int x = 2; x < root; x++)
    {
        while (!(n%x))
        {
            printf("%i ", x);
            n/=x;
        }
    }
    if (n >= 2) printf("%i", n);
}

int main() 
{
    int n, a;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        prime(a);
        printf("\n");
    }
    return 0;
}
