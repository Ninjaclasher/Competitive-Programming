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
    long double ans = 0;
    for (int x = 1; x < n; x++)
        ans = max(ans, (long double)abs(arr[x].second - arr[x-1].second) / (arr[x].first - arr[x-1].first));
    printf("%.10Lf\n", ans);
}
