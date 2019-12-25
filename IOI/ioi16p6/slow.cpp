// not as slow O(NK)
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
    vector<vector<long long>> dp(nn, vector<long long>(k+1, LONG_MAX));
    deque<int> buf;

    auto f = [&](int x, int kk)
    {
        return dp[x][kk - 1] + sq(points[x+1].first - 1) - sq(max(0, points[x].second - points[x+1].first + 1));
    };

    auto calc_top = [&](int x, int y, int kk)
    {
        swap(x, y);
        return f(x, kk) - f(y, kk);
    };
    auto calc_bot = [&](int x, int y, int kk)
    {
        swap(x, y);
        return (long long)points[x+1].first - points[y+1].first;
    };

    //auto calc2 = [&](int x, int y, int kk)
    //{
    //    return calc_top(x, y, kk) / (long double) calc_bot(x, y, kk);
    //};

    for (int y = 1; y <= k; y++)
    {
        buf.clear();
        for (int x = 0; x < nn; x++)
        {
            dp[x][y] = min(dp[x][y-1], calc(0, x));
            if (y == 1)
                continue;
            while (buf.size() >= 2 && calc_top(buf[0], buf[1], y) < calc_bot(buf[0], buf[1], y) * 2 * points[x].second)
                buf.pop_front();
            if (!buf.empty())
            {
                dp[x][y] = min(dp[x][y], dp[buf[0]][y-1] + calc(buf[0]+1, x));
            }
            while (buf.size() >= 2)
            {
                int sz = buf.size();
                if (calc_top(buf[sz-2], buf[sz-1], y) * calc_bot(buf[sz-1], x, y) > calc_bot(buf[sz-2], buf[sz-1], y) * calc_top(buf[sz-1], x, y))
                    buf.pop_back();
                else
                    break;
            }
            //cout << x << " " << y << " " << dp[x][y] << endl;
            buf.push_back(x);
        }
    }
    return dp[nn-1][k];
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
