#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, b;
    map<int,int> mp;
    map<pair<int,int>, int> tmp;
    scanf("%i", &n);
    assert(1 <= n && n <= 100000);
    long long ans = 0;
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &m, &b);
        assert(abs(m) <= 1000000000);
        assert(abs(b) <= 1000000000);
        ans += x - mp[m];
        mp[m]++;
        ans += tmp[{m, b}];
        tmp[{m, b}]++;
    }
    printf("%lli\n", ans);
}
