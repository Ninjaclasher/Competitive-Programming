//Binary Search version
#include <bits/stdc++.h>

using namespace std;

struct task
{
    int l, r;
    friend bool operator<(task &a, task &b)
    {
        return a.l < b.l || (a.l == b.l && a.r < b.r);
    }
};

bool cmp2(task a, task b)
{
    return a.r < b.r || (a.r == b.r && a.l < b.l);
}

map<int,int> dp;

int performDP(vector<task> &cur)
{
    sort(cur.begin(), cur.end(), cmp2);
    dp.clear();
    dp[0] = 0;
    int ret = 0;
    for (auto &y : cur)
    {
        auto it = dp.lower_bound(y.l);
        if (it == dp.begin())
            abort();
        --it;
        auto it2 = dp.end();
        --it2;
        int v = max(it2->second, it->second + 1);
        dp[y.r] = max(dp[y.r], v);
        ret = max(ret, v);
    }
    return ret;
}

int main()
{
    int n, k;
    assert(scanf("%i%i", &n, &k) == 2);
    assert(1 <= n && n <= 1000000);
    assert(1 <= k && k <= 2);
    vector<task> arr(n);
    for (auto &x : arr)
    {
        assert(scanf("%i%i", &x.l, &x.r) == 2);
        assert(1 <= x.l && x.l <= x.r && x.r <= 1000000000);
    }
    sort(arr.begin(), arr.end());
    vector<task> used, tmpDiscard;
    for (auto &x : arr)
    {
        if (used.empty() || used.back().r < x.l)
            used.push_back(x);
        else
            tmpDiscard.push_back(x);
    }
    // One can technically check for intersections in linear time by checking the line segment before and after
    // But I don't trust myself to code it correctly, so I'll just binary search instead....
    map<pair<int,int>, vector<task>> intersect2;
    vector<vector<task>> intersect1 (n+1);
    for (auto &x : tmpDiscard)
    {
        // find lowerbound intersection
        int l = 0, r = used.size()-1;
        while (l <= r)
        {
            int m = l+r>>1;
            if (used[m].r < x.l)
                l = m+1;
            else
                r = m-1;
        }
        int lower = l;
        l = 0, r = used.size()-1;
        // upper
        while (l <= r)
        {
            int m = l+r>>1;
            if (used[m].l > x.r)
                r = m-1;
            else
                l = m+1;
        }
        int upper = r;
        if (lower < 0)
            abort();
        if (upper >= n)
            abort();
        // TOO MANY INTERSECTIONS
        if (upper-lower >= k)
            continue;
        if (lower == upper)
            intersect1[lower].push_back(x);
        else
            intersect2[{lower, upper}].push_back(x);
    }
    int sz = used.size();
    int ans = sz;
    vector<int> memo(sz);
    for (int x = 0; x < sz; x++)
        memo[x] = performDP(intersect1[x]);
    sort(memo.begin(), memo.end());
    ans = max(ans, memo.back() + sz - 1);
    if (k == 2 && sz > 1)
    {
        for (auto &x : intersect2)
        {
            vector<task> &cur = x.second;
            for (auto &y : intersect1[x.first.first])
                cur.push_back(y);
            for (auto &y : intersect1[x.first.second])
                cur.push_back(y);
            ans = max(ans, performDP(cur) + sz - 2);
        }
        ans = max(ans, memo[sz-1] + memo[sz-2] + sz - 2);
    }
    printf("%i\n", ans);
}
