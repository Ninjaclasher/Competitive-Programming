#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    assert(scanf("%i", &n) == 1);
    assert(1 <= n && n <= 100000);
    if (n == 1)
        return 0 * printf("0\n");
    vector<int> arr(n);
    long long ans = LONG_MAX;
    for (auto &x : arr)
        assert(scanf("%i", &x) == 1), assert(1 <= x && x <= 1000000000);
    for (int x = 1; x < n; x++)
    {
        if (n%x)
            continue;
        long long cur = 0;
        for (int y = 0; y < x; y++)
        {
            vector<int> cc;
            for (int z = y; z < n; z += x)
                cc.push_back(arr[z]);
            sort(cc.begin(), cc.end());
            long long mid = cc[cc.size()/2];
            for (auto &z : cc)
                cur += abs(z - mid);
        }
        ans = min(ans, cur);
    }
    printf("%lli\n", ans);
}
