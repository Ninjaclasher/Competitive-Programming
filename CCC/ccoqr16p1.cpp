#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    map<int,vector<int>> xx, yy;
    vector<pair<int,int>> arr(n);
    for (auto &x : arr)
    {
        scanf("%i%i", &x.first, &x.second);
        xx[x.first].push_back(x.second);
        yy[x.second].push_back(x.first);
    }
    for (auto &x : xx)
        sort(x.second.begin(), x.second.end());
    for (auto &y : yy)
        sort(y.second.begin(), y.second.end());
    long long ans = 0;
    for (auto &x : arr)
    {
        auto &xc = xx[x.first];
        auto &yc = yy[x.second];
        auto x1 = lower_bound(xc.begin(), xc.end(), x.second);
        auto x2 = lower_bound(xc.begin(), xc.end(), x.second+1);
        auto y1 = lower_bound(yc.begin(), yc.end(), x.first);
        auto y2 = lower_bound(yc.begin(), yc.end(), x.first+1);
        ans += (x1-xc.begin())*(xc.end()-x2) * (long long) (y1-yc.begin())*(yc.end()-y2);
    }
    printf("%lli\n", ans*2);
}

