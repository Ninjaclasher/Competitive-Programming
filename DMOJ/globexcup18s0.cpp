#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> xx, yy;
    int n;
    scanf("%i", &n);
    assert(1 <= n && n <= 100000);
    vector<pair<int,int>> po(n);
    for (auto &x : po)
    {
        scanf("%i%i", &x.first, &x.second);
        xx.push_back(x.first);
        yy.push_back(x.second);
        assert(1 <= x.first && x.first <= 1000000000);
        assert(1 <= x.second && x.second <= 1000000000);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    long long ans = 0;
    int x = xx[n/2], y = yy[n/2];
    for (auto &p : po)
        ans += abs(p.first-x)+abs(p.second-y);
    printf("%lli\n", ans);
}
