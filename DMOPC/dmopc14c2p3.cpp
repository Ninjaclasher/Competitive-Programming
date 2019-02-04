#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<long long> e(n), l(n);
    for (auto &x : e)
        scanf("%lli", &x);
    for (auto &x : l)
        scanf("%lli", &x);
    sort(e.begin(), e.end());
    sort(l.rbegin(), l.rend());
    long long ans = 0;
    for (int x = 0; x < n; x++)
        ans += e[x] * l[x];
    printf("%lli\n", ans);
}
