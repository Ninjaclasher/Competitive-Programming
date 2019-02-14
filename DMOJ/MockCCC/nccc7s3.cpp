#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<long long, long long>> arr(n);
    for (auto &x : arr)
        scanf("%lli%lli", &x.first, &x.second);
    sort(arr.begin(), arr.end());
    long long ans = (long long)n*(n-1)*(n-2)/2/3;
    for (int x = 0; x < n; x++)
    {
        map<pair<long long,long long>,long long> mp;
        for (int y = x+1; y < n; y++)
        {
            long long yy = arr[y].second - arr[x].second;
            long long xx = arr[y].first - arr[x].first;
            long long gg = abs(__gcd(xx, yy));
            xx /= gg;
            yy /= gg;
            if (xx < 0)
                xx = -xx, yy = -yy;
            long long &cur = mp[{xx, yy}];
            ans -= cur;
            cur++;
        }
    }
    printf("%lli\n", ans);
}
