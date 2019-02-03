#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, a, b;
    int k, q;
    scanf("%lli%i%i", &n, &k, &q);
    while (q--)
    {
        scanf("%lli%lli", &a, &b);
        if (k == 1)
            printf("%lli\n", abs(a-b));
        else
        {
            int ans = 0;
            while (a != b)
            {
                ans++;
                if (a > b)
                    swap(a, b);
                b += k-2;
                b /= k;
            }
            printf("%i\n", ans);
        }
    }
}

