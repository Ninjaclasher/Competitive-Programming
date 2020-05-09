#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
    for (int x = 2; x <= sqrt(n); x++)
        if (n%x == 0)
            return false;
    return true;
}

void print(int s, int a, int b, int c)
{
    printf("%i = %i + %i + %i\n", s, a, b, c);
}

void print(int s, int a, int b)
{
    printf("%i = %i + %i\n", s, a, b);
}

int main()
{
    for (int tttt = 0; tttt < 5; tttt++)
    {
        int n;
        scanf("%i", &n);
        if (prime(n))
        {
            cout<<n<<" = "<<n<<"\n";
            goto nxt;
        }
        for (int x = n/2; x >= 2; x--)
        {
            if (prime(x))
            {
                if (prime(n-x))
                {
                    print(n, x, n-x);
                    goto nxt;
                }
                else
                {
                    int ma = INT_MAX;
                    for (int y = x; y <= (n-x-y); y++)
                        if (prime(y) && prime(n-x-y))
                            ma = y;
                    if (ma != INT_MAX)
                    {
                        print(n, x, ma, n-x-ma);
                        goto nxt;
                    }
                }
            }
        }
        nxt:;
    }
}
