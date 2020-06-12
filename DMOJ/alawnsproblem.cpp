#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        long long v;
        scanf("%i%lli", &n, &v);
        vector<int> arr(n), pref_max(n);
        int mi = INT_MAX;
        for (auto &x : arr)
            scanf("%i", &x), mi = min(mi, x);
        pref_max[0] = arr[0];
        for (int x = 1; x < n; x++)
            pref_max[x] = max(pref_max[x-1], arr[x]);
        int _en = n-1;
        while (_en >= 0 && arr[_en] == pref_max[_en])
            _en--;
        if (_en < 0)
            printf("0\n");
        else
        {
            long long ma = pref_max[_en];
            if (ma * mi <= v)
                printf("0\n");
            else
            {
                long long x = mi - v / ma;
                assert((mi - x) * ma <= v && (mi - x + 1) * ma > v);
                printf("%lli\n", x);
            }
        }
    }
}
