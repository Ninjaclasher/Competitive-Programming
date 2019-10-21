#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<long long> arr(n);
    for (auto &x : arr)
        scanf("%lli", &x);
    sort(arr.begin(), arr.end());
    int nn = n/2;
    int nk = n - nn;
    double q1 = (nn & 1) ? arr[nn/2] : (arr[nn/2] + arr[nn/2-1]) / 2.0;
    double q2 = (n & 1) ? arr[n/2] : (arr[n/2] + arr[n/2-1]) / 2.0;
    double q3 = (nn & 1) ? arr[nk + nn/2] : (arr[nk + nn/2] + arr[nk + nn/2-1]) / 2.0;
    printf("%lli %lli %.1lf %.1lf %.1lf\n", arr[0], arr[n-1], q1, q2, q3);
}
