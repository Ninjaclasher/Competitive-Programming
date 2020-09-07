#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long m;
    scanf("%i%lli", &n, &m);
    vector<long long> d(n);
    for (auto &x : d)
        scanf("%lli", &x);
    int l = 0, r = 0;
    int mi_len = INT_MAX;
    long long cur_sum = 0;
    while (r < n)
    {
        while (r < n && cur_sum < m)
            cur_sum += d[r++];
        if (cur_sum >= m)
            mi_len = min(mi_len, r - l);
        cur_sum -= d[l++];
    }
    printf("%i\n", mi_len == INT_MAX ? -1 : mi_len);
}
