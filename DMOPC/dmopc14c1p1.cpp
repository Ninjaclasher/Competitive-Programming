#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    if (n&1)
        printf("%i\n", arr[n/2]);
    else
        printf("%i\n", (int)round((arr[n/2] + arr[n/2-1])/2.0));
}
