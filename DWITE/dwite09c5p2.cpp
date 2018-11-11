#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
    for (int x = 2; x <= sqrt(n); x++)
        if (n%x == 0)
            return 0;
    return 1;
}

int main()
{
    for (int x = 0; x < 5; x++)
    {
        int n;
        scanf("%i", &n);
        int i = n-1, j = n+1, ii = 0, jj = 0;
        while(1)
        {
            if (i >= 2)
                ii += prime(i);
            jj += prime(j);
            if (jj == 2)
            {
                printf("%i\n", j);
                break;
            }
            if (ii == 2)
            {
                printf("%i\n", i);
                break;
            }
            i--, j++;
        }
    }
}

