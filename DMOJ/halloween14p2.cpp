#include <bits/stdc++.h>

using namespace std;

int main()
{
    char t;
    int n, l = 1, i = 1, a, b;
    long long w;
    scanf("%i%lli", &n, &w);
    vector<long long> ans(500010), psa(500010), wid(500010);
    for (int x = 1; x <= n; x++)
    {
        scanf(" %c", &t);
        if (t == 'D')
            i--;
        else
        {
            scanf("%i%i", &a, &b);
            wid[i] = wid[i-1]+a;
            psa[i] = psa[i-1]+b;
            l = lower_bound(wid.begin(), wid.begin()+i+1, wid[i]-w)-wid.begin()+1;
            printf("%lli\n", ans[i] = max(psa[i]-psa[l-1], ans[i-1]));
            i++;
        }
    }
}
