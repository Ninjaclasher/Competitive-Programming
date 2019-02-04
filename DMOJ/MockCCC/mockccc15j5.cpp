#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b;
    scanf("%i", &n);
    map<int,vector<int>> mpx, mpy;
    while (n--)
    {
        scanf("%i%i", &a, &b);
        mpx[a].push_back(b);
        mpy[b].push_back(a);
    }
    for (auto &x : mpx)
        sort(x.second.begin(), x.second.end());
    for (auto &x : mpy)
        sort(x.second.begin(), x.second.end());
    scanf("%i", &m);
    vector<pair<int,int>> arr(m);
    for (auto &x : arr)
        scanf("%i%i", &x.first, &x.second);
    long long ans = 0;
    for (int x = 0; x < m-1; x++)
    {
        auto a = arr[x];
        auto b = arr[x+1];
        if (a.first == b.first)
        {
            auto &q = mpx[a.first];
            ans += upper_bound(q.begin(), q.end(), max(b.second, a.second)) - lower_bound(q.begin(), q.end(), min(a.second, b.second));
        }
        else
        {
            auto &q = mpy[a.second];
            ans += upper_bound(q.begin(), q.end(), max(b.first, a.first)) - lower_bound(q.begin(), q.end(), min(a.first, b.first));
        }
    }
    printf("%lli\n", ans);
}
