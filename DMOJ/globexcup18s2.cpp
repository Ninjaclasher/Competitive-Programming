#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, k;
    scanf("%lli%lli%lli", &n, &m, &k);
    long long cur = 0, ans = 0, thresh = n*k;
    vector<pair<long long, long long>> arr(n);
    for (auto &x : arr)
        scanf("%lli%lli", &x.second, &x.first), cur += x.second;
    sort(arr.begin(), arr.end());
    if (cur >= thresh)
        return 0 * printf("0\n");
    for (int x = 0; x < n; x++)
    {
        long long add = min(m-arr[x].second, thresh-cur);
        ans += add*arr[x].first;
        cur += add;
        if (cur == thresh)
            break;
    }
    printf("%lli\n", ans);
}
