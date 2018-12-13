#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<long long, long long>> po(n);
    vector<long long> xx(n), yy(n);
    for (int x = 0; x < n; x++)
    {
        scanf("%lli%lli", &po[x].first, &po[x].second);
        xx[x] = po[x].first - po[x].second;
        yy[x] = po[x].first + po[x].second;
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    
    long long a = xx[n/2], b = yy[n/2];
    
    long long X = (a+b)/2, Y = (b-a)/2;

    long long mi = LONG_MAX;

    for (long long x = X-1; x <= X+1; x++)
    {
        for (long long y = Y-1; y <= Y+1; y++)
        {
            long long cur = 0;
            for (auto &u : po)
                cur += max(abs(u.first-x), abs(u.second-y));
            mi = min(mi, cur);
        }
    }
    printf("%lli\n", mi);
    
}
