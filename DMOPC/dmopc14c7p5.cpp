#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, a, b, c;
    scanf("%lli%lli", &n, &m);
    scanf("%lli%lli%lli", &a, &b, &c);
    vector<long long> arr(n);
    vector<long long> psa(n);
    for (auto &x : arr)
        scanf("%lli", &x);
    sort(arr.begin(), arr.end());
    psa[0] = (arr[0]-1) * b;
    for (int x = 1; x < n; x++)
        psa[x] = psa[x-1] + (arr[x]-1) * b;
    long long mi = psa[n-1], curV = 0;
    for (int x = n-1; x >= 0; x--)
    {
        curV += (arr[x] - 1) * a + c * (n-x-1);
        mi = min(mi, (x ? psa[x-1] : 0) + curV);
    }
    printf("%lli\n", mi);
}
