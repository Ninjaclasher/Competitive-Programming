#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    scanf("%i", &n);
    while (n--)
    {
        int c = 0;
        scanf("%i", &a);
        for (int x = 1; x < a; x++)
            if (a%x==0)
                c+=x;
        if (c < a)
            printf("%i is a deficient number.\n", a);
        else if (c > a)
            printf("%i is an abundant number.\n", a);
        else
            printf("%i is a perfect number.\n", a);
    }
}
