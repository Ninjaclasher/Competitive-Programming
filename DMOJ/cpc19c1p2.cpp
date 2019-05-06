#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    int ma = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        while (arr[r]-arr[l] > k)
            ++l;
        ma = max(ma, r-l+1);
        r++;
    }
    printf("%i\n", ma);
}
