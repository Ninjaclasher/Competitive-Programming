#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<long long> arr(MAXN), psa(MAXN);

int n, m;

bool test(vector<long long> &cur)
{
    int curIdx = 0;
    vector<int> ret;
    for (auto &group : cur)
    {
        int l = curIdx+1, r = n;
        if (l > r)
            return true;
        while (l <= r)
        {
            int mid = l+r>>1;
            if (psa[mid]-psa[curIdx] > group)
                r = mid-1;
            else
                l = mid+1;
        }
        curIdx = r;
    }
    return curIdx == n;
}

bool solve(long long bound, vector<long long> cur)
{
    for (auto &group : cur)
    {
        if (psa[n] / bound < group)
            return true;
        group *= bound;
    }
    do
    {
        if (test(cur))
            return true;
    }
    while (next_permutation(cur.begin(), cur.end()));
    return false;
}

int main()
{
    assert(scanf("%i%i", &n, &m) == 2);
    assert(1 <= n && n <= 100000);
    assert(1 <= m && m <= 8);
    
    long long l = 1, r = 0;
    for (int x = 1; x <= n; x++)
    {
        assert(scanf("%lli", &arr[x]) == 1);
        assert(1 <= arr[x] && arr[x] <= 1'000'000'000);
        psa[x] = psa[x-1] + arr[x];
        r += arr[x];
    }
    psa[n+1] = LLONG_MAX;
    vector<long long> g(m);
    for (auto &x : g)
    {
        assert(scanf("%lli", &x) == 1);
        assert(1 <= x && x <= 1'000'000'000);
    }
    sort(g.begin(), g.end());
    while (l <= r)
    {
        long long mid = l+r>>1;
        if (solve(mid, g))
            r = mid-1;
        else
            l = mid+1;
    }
    printf("%lli\n", l);
}
