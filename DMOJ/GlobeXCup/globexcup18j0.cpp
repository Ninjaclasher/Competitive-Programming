#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    assert(1 <= m && m <= n && n <= 100000);
    long long s = 0;
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x), s += x, assert(1 <= x && x <= 100000);
    sort(arr.begin(), arr.end());
    for (int x = 0; x < m; x++)
        s -= arr[x];
    printf("%lli\n", s);
}
