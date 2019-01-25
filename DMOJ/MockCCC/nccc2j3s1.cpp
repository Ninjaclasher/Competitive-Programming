#include <bits/stdc++.h>

using namespace std;

vector<long long> psa(60);

int main()
{
    long long n, sum = 0;
    scanf("%lli", &n);
    vector<long long> aa(n);
    for (int x = 0; x < n; x++)
        scanf("%lli", &aa[x]);
    sort(aa.begin(), aa.end());
    for (int x = n-1; x >= 0; x--)
        psa[x] = psa[x+1] + aa[x];
    for (int x = 0, y = n-1; x < n-1; x++, y = max(y, x+1))
    {
        long long qq = psa[y]-aa[y]*(n-y);
        while (x < y && qq < aa[x])
            y--, qq = psa[y]-aa[y]*(n-y);
        long long a = aa[y], b = n;
        if (qq != aa[x])
        {
            y++;
            a = aa[y] - (aa[x]-psa[y]+aa[y]*(n-y))/(n-y) - 1;
            b = n - (psa[y]-a*(n-y)-aa[x]);
        }
        for (int z = y; z < n; z++)
            aa[z] = a + (z >= b);
        for (int z = n-1; z >= 0; z--)
            psa[z] = psa[z+1] + aa[z];
        sum += aa[x];
    }
    printf("%lli\n", sum);
}
