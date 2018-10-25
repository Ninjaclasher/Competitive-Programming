#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, a, b, c;
    scanf("%i%i", &n, &t);
    vector<int> arr(n+5);
    while (t--)
    {
        scanf("%i%i%i", &a, &b, &c);
        arr[a] += c;
        arr[b+1] -= c;
    }
    for (int x = 1; x <= n; x++)
        arr[x] += arr[x-1];
    int l = 1, r = 1, ma = 0;
    long long cur = 0, ll;
    scanf("%lli", &ll);
    while (r <= n)
    {
        while (r <= n && cur+arr[r] <= ll)
            cur += arr[r++];
        ma = max(ma, r-l);
        cur -= arr[l++];
    }
    printf("%i\n", ma);
}

