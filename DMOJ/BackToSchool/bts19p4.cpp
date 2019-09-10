// full solution
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    assert(1 <= n && n <= 100000);
    assert(1 <= m && m <= 1000000000);
    vector<long long> arr(n);
    for (auto &x : arr)
        scanf("%lli", &x), assert(1 <= x && x <= m);
    sort(arr.begin(), arr.end());
    for (int x = 0; x < n; x++)
        arr.push_back(arr[x] + m);
    long long cur = 0;
    for (int x = 0; x < n; x++)
        cur += abs(arr[x] - arr[0]);
    int l = 0, r = 0;
    long long mi = cur;
    while (l < n)
    {
        while (r < l + n/2)
        {
            r++;
            cur += abs(arr[r] - arr[r-1]) * (2 * r - 2 * l - n);
        }
        mi = min(mi, cur);
        cur -= abs(arr[l] - arr[r]);
        cur += abs(arr[l + n] - arr[r]);
        l++;
    }
    printf("%lli\n", mi);
}
