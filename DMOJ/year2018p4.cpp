#include <bits/stdc++.h>

using namespace std;

static inline long long dig(long long a)
{
    long long s = 0;
    for (;a; a/=10)
        s += a%10;
    return s;
}

int main()
{
    vector<long long> p(19, 1);
    long long l, u, a = INT_MAX, b = INT_MIN;
    for (int x = 1; x < p.size(); p[x] = p[x-1]*10, x++);
    scanf("%lli%lli", &l, &u);
    reverse(p.begin(), p.end());
    for (long long x = l; x <= u;)
    {
        a = min(a, dig(x));
        for (auto &y : p)
        {
            if (!(x%y))
            {
                x += y;
                break;
            }
        }
    }
    for (long long x = l; x <= u;)
    {
        b = max(b, dig(x));
        for (auto &y : p)
        {
            if (x%y == y-1)
            {
                x += y;
                break;
            }
        }        
    }
    printf("%lli", b-a+1);
}
