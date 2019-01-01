#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> kk(k);
    kk[0] = 1;
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    long long ans = 0, cur = 0;
    for (int x = 0; x < n; x++)
    {
        cur += arr[x];
        ans += kk[cur%k];
        kk[cur%k]++;
    }
    printf("%lli\n", ans);
}
