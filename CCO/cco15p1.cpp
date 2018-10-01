#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, w;
    scanf("%i%i", &n, &w);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    auto it = lower_bound(arr.begin(), arr.end(), w);
    long long mi = 0;
    if (it != arr.end())
    {
        mi += *it-w;
        for (auto x = it+1; x != arr.end(); ++x)
            mi += *x - *(x-1);
    }
    if (it != arr.begin())
    {
        --it;
        mi += w-*it;
        for (auto x = it; x != arr.begin(); --x)
            mi += *x - *(x-1);
    }
    long long ma = abs(arr.back()-w);
    for (int x = 0; x < n/2; x++)
    {
        ma += max(arr[n-x-1]-arr[x], abs(arr[x]-w));
        if (x != n/2-1 || (n&1))
            ma += max(arr[n-x-2]-arr[x], abs(w-arr[n-x-2]));
    }
    reverse(arr.begin(), arr.end());
    long long ma2 = abs(arr.back()-w);
    for (int x = 0; x < n/2; x++)
    {
        ma2 += max(arr[x]-arr[n-x-1], abs(arr[x]-w));
        if (x != n/2-1 || (n&1))
            ma2 += max(arr[x]-arr[n-x-2], abs(w-arr[n-x-2]));
    }
    printf("%lli %lli\n", mi, max(ma, ma2));
}

