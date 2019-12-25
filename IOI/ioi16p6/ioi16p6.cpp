// fast O(N log N)
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

vector<pair<int,int>> points;
int nn;

long long sq(long long v)
{
    return v * v;
}

long long calc(int i, int j)
{
    return max(0LL, sq(points[j].second - points[i].first + 1) - (i ? sq(max(0, points[i-1].second - points[i].first + 1)) : 0));
}

pair<long long, int> chk(long long cc)
{
    vector<pair<long long, int>> dp(nn);
    deque<int> buf;

    auto f = [&](int x)
    {
        return dp[x].first + sq(points[x+1].first - 1) - sq(max(0, points[x].second - points[x+1].first + 1));
    };
    auto calc_top = [&](int x, int y)
    {
        swap(x, y);
        return f(x) - f(y);
    };
    auto calc_bot = [&](int x, int y)
    {
        swap(x, y);
        return (long long)points[x+1].first - points[y+1].first;
    };

    for (int x = 0; x < nn; x++)
    {
        dp[x] = make_pair(calc(0, x) + cc, 1);
        while (buf.size() >= 2 && calc_top(buf[0], buf[1]) < calc_bot(buf[0], buf[1]) * 2 * points[x].second)
            buf.pop_front();
        if (!buf.empty())
            dp[x] = min(dp[x], make_pair(dp[buf[0]].first + calc(buf[0]+1, x) + cc, dp[buf[0]].second + 1));
        while (buf.size() >= 2)
        {
            int sz = buf.size();
            if (calc_top(buf[sz-2], buf[sz-1]) * calc_bot(buf[sz-1], x) > calc_bot(buf[sz-2], buf[sz-1]) * calc_top(buf[sz-1], x))
                buf.pop_back();
            else
                break;
        }
        //cout << x << " " << y << " " << dp[x][y] << endl;
        buf.push_back(x);
    }
    return dp[nn-1];
}

long long take_photos(int n, int m, int k, int *r, int *c)
{
    vector<pair<int,int>> tmp(n);
    for (int x = 0; x < n; x++)
    {
        if (r[x] >= c[x])
            swap(r[x], c[x]);
        tmp[x] = make_pair(r[x], c[x]);
    }
    sort(tmp.begin(), tmp.end(), cmp);
    for (auto &x : tmp)
    {
        if (!points.empty() && points.back().first <= x.first && points.back().second >= x.second)
            continue;
        points.push_back(x);
    }
    nn = points.size();

    long long l = 0, h = 1e13;
    while (l <= h)
    {
        long long mid = l+h>>1;
        // too many photos - increase cost
        if (chk(mid).second > k)
            l = mid+1;
        else
            h = mid-1;
    }
    auto ans = chk(l);
    assert(ans.second <= k);
    return ans.first - k * l;
}

int main()
{
    int n, m, k;
    scanf("%i%i%i", &n, &m, &k);
    int r[n], c[n];
    for (int x = 0; x < n; x++)
        scanf("%i%i", &r[x], &c[x]);
    printf("%lli\n", take_photos(n, m, k, r, c));
}
