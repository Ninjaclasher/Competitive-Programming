#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long m;
    scanf("%i%lli", &n, &m);
    vector<long long> arr(n);
    for (auto &x : arr)
        scanf("%lli", &x);
    int l = 0, r = 0, ma = 0;
    long long sum = 0;
    while (l < n)
    {
        while (r < n && sum + arr[r] < m)
            sum += arr[r++];
        ma = max(ma, r-l);
        sum -= arr[l];
        l++;
    }
    printf("%i\n", ma);
}
