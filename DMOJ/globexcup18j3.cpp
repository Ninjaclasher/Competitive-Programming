#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
    if (n == 1)
        return false;
    for (int x = 2; x <= sqrt(n); x++)
        if (n%x == 0)
            return false;
    return true;
}

int main()
{
    int n, cnt = 0, a;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        if (prime(a))
        {
            int b = 0;
            for (; a; a /= 10)
                b += a%10;
            if (prime(b))
                cnt++;
        }
    }
    printf("%i\n", cnt);
}
