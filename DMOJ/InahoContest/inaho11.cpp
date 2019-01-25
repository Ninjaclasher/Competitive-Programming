#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int mi[10], ma[10];
long long len[10];

int main()
{
    for (int x = 0; x < 10; x++)
        mi[x] = INT_MAX, ma[x] = INT_MIN;
    int n, m, a;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        for (int x = 0; x < n; x++)
        {
            scanf("%i", &a);
            mi[x] = min(mi[x], a);
            ma[x] = max(ma[x], a);
        }
    }
    for (int x = 0; x < n; x++)
        len[x] = ma[x]-mi[x];
    long long area = 0;
    for (int x = 0; x < n; x++)
    {
        long long cur = 1;
        for (int y = 0; y < n; y++)
            if (x ^ y)
                cur = (cur*len[y])%MOD;
        area += cur;
    }
    printf("%lli\n", area*2%MOD);
}
