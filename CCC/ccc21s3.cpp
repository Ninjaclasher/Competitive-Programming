#include <bits/stdc++.h>

using namespace std;

struct person
{
    int p, w, d;
};

long long calc(vector<person> &arr, int m)
{
    long long ans = 0;
    for (auto &x : arr)
    {
        ans += (long long)max(0, abs(m - x.p) - x.d) * x.w;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<person> arr(n);
    for (auto &x : arr)
        scanf("%i%i%i", &x.p, &x.w, &x.d);
    int l = 0, r = 1000000001;
    while (l <= r)
    {
        int m = l+r>>1;
        if (calc(arr, m) > calc(arr, m + 1))
            l = m + 1;
        else
            r = m - 1;
    }
    printf("%lli\n", calc(arr, l));
}
