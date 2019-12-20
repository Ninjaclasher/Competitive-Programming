#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<long long> d(MAXN);
vector<int> h(MAXN);
vector<int> ans_r(MAXN), ans_l(MAXN);

__int128 query_d(int i, int j)
{
    return (__int128)(d[j] - d[i]);
}

int main()
{
    int n;
    assert(scanf("%i", &n) == 1);
    assert(1 <= n && n <= 200000);
    for (int x = 1; x <= n; x++)
        assert(scanf("%i", &h[x]) == 1), assert(1 <= h[x] && h[x] <= 1000000000);
    for (int x = 2; x <= n; x++)
    {
        assert(scanf("%lli", &d[x]) == 1);
        assert(1 <= d[x] && d[x] <= 1000000000);
        d[x] += d[x-1];
    }
    vector<int> buf;
    int ma = -1;
    for (int x = 1; x <= n; x++)
    {
        while (buf.size() >= 2)
        {
            int i = buf[buf.size()-2];
            int j = buf[buf.size()-1];
            __int128 lhs = (h[i] - h[x]) * query_d(j, x);
            __int128 rhs = (h[j] - h[x]) * query_d(i, x);
            if (lhs >= rhs)
                buf.pop_back();
            else
                break;
        }
        if (h[x] >= ma)
            ans_l[x] = ma;
        else
            ans_l[x] = buf.empty() ? -1 : h[buf.back()];
        ma = max(ma, h[x]);
        buf.push_back(x);
    }
    buf.clear();
    ma = -1;
    for (int x = n; x >= 1; x--)
    {
        while (buf.size() >= 2)
        {
            int i = buf[buf.size()-2];
            int j = buf[buf.size()-1];
            __int128 lhs = (h[i] - h[x]) * query_d(x, j);
            __int128 rhs = (h[j] - h[x]) * query_d(x, i);
            if (lhs >= rhs)
                buf.pop_back();
            else
                break;
        }
        if (h[x] >= ma)
            ans_r[x] = ma;
        else
            ans_r[x] = buf.empty() ? -1 : h[buf.back()];
        ma = max(ma, h[x]);
        buf.push_back(x);
    }
    for (int x = 1; x <= n; x++)
        printf("%i %i\n", ans_l[x], ans_r[x]);
}
