#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
    for (int x = 2; x * x <= n; x++)
        if (n % x == 0)
            return false;
    return true;
}

int main()
{
    for (int x = 0; x < 5; x++)
    {
        long long ans = 0;
        int a;
        scanf("%i", &a);
        do
            ans += a * prime(a);
        while (a-->2);
        printf("%lli\n", ans);
    }
}
