#include <bits/stdc++.h>

using namespace std;

bool cw(pair<int, int> &o, pair<int,int> &a, pair<int,int> &b)
{
    return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first) < 0;
}

vector<pair<int,int>> convex_hull(vector<pair<int,int>> arr)
{
    int k = 0;
    if (arr.size() <= 2)
        return arr;
    sort(arr.begin(), arr.end());
    vector<pair<int,int>> res(2*arr.size());
    for (int x = 0; x < arr.size(); x++)
    {
        while (k >= 2 && !cw(res[k-2], res[k-1], arr[x])) --k;
        res[k++] = arr[x];
    }
    int t = k+1;
    for (int x = arr.size()-2; x >= 0; x--)
    {
        while (k >= t && !cw(res[k-2], res[k-1], arr[x])) --k;
        res[k++] = arr[x];
    }
    res.resize(k-1);
    return res;
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<int,int>> arr(n);
    for (auto &x : arr)
        scanf("%i%i", &x.first, &x.second);
    auto ret = convex_hull(arr);
    long long area = 0;
    for (int x = 0; x < ret.size(); x++)
        area += (ret[x].first * ret[(x+1)%ret.size()].second) - (ret[x].second * ret[(x+1)%ret.size()].first);
    printf("%lli\n", abs(area/100));
}
