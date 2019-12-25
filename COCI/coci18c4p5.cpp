// O(NlogN)
#include <bits/stdc++.h>

using namespace std;

const long double MULT = 100000;

long double calc(int i, int tot)
{
    return MULT * i / tot;
}

int n, k;

pair<long double, int> chk(long double cc)
{
    vector<pair<long double, int>> dp(n+1);

    auto f = [&](int x, int y)
    {
        return (dp[x].first - dp[y].first) / (x - y);
    };

    deque<int> buf;
    buf.push_back(0);
    for (int y = 1; y <= n; y++)
    {
        while (buf.size() >= 2 && f(buf[0], buf[1]) > MULT / y)
            buf.pop_front();
        dp[y] = make_pair(dp[buf[0]].first + calc(y - buf[0], y) + cc, dp[buf[0]].second + 1);
        while (buf.size() >= 2)
        {
            int sz = buf.size();
            if (f(buf[sz - 2], buf[sz - 1]) < f(buf[sz - 1], y))
                buf.pop_back();
            else
                break;
        }
        buf.push_back(y);
    }
    return dp[n];
}

int main()
{
    scanf("%i%i", &n, &k);

    long double l = -1e11, r = 0;
    while (r-l > 1e-10)
    {
        long double m = (l+r)/2;
        // too many rounds - less cost
        if (chk(m).second > k)
            r = m;
        else
            l = m;
    }
    printf("%.10Lf\n", (chk(l).first - k * l) / MULT);
}
