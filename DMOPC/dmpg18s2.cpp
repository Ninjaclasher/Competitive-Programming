#include <bits/stdc++.h>

using namespace std;

vector<long long> psa(200005);

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%lli", &psa[x]);
        psa[x] += psa[x-1];
    }
    long long ans = 0;
    for (int x = 1; x <= n; x++)
    {
        ans += psa[n-x+1] - psa[x-1];
        printf("%lli\n", ans);
    }
}
