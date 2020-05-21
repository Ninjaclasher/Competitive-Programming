#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    assert(1 <= n && n <= 100);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x), assert(1 <= x && x <= 1000000000);
    sort(arr.begin(), arr.end());
    for (int x = 2; x < n; x++)
        assert(arr[x] - arr[x-1] == arr[x-1] - arr[x-2]);
    for (int x = 0; x < n; x++)
        printf("%i%c", arr[x], (x == n-1 ? '\n' : ' '));
}
