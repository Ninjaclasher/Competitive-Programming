#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    vector<int> cnt(1000005);
    scanf("%i%i", &n, &k);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int l = 0, r = 0, cur = 0;
    long long ans = 0;
    while (l < n)
    {
        while (r < n && cur < k)
        {
            cnt[arr[r]]++;
            if (cnt[arr[r]] == 1)
                cur++;
            r++;
        }
        if (cur < k)
            break;
        ans += n-r+1;
        cnt[arr[l]]--;
        if (cnt[arr[l]] == 0)
            cur--;
        l++;
    }
    printf("%lli\n", ans);
}
