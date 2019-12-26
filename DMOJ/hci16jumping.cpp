#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, c;
    scanf("%i%i", &c, &n);
    vector<string> arr(n);
    for (auto &x : arr)
        cin>>x;
    vector<long long> dp(n, LONG_MAX);
    auto f = [&](int i, int j)
    {
        return (long double)(dp[i] - dp[j] + i * i - j * j) / (i - j);
    };
    for (int x = 0; x < n; x++)
        dp[x] = (arr[x][0] == '0' ? LONG_MAX : 0);
    for (int x = 1; x < c; x++)
    {
        vector<long long> dp2 = dp;
        deque<int> buf;
        for (int y = 0; y < n; y++)
        {
            while (buf.size() >= 2 && f(buf[0], buf[1]) < 2 * y)
                buf.pop_front();
            if (arr[y][x] == '0')
                dp2[y] = LONG_MAX;
            else if (!buf.empty())
                dp2[y] = min(dp2[y], dp[buf[0]] + (buf[0] - y) * (buf[0] - y));
            if (dp[y] < LONG_MAX)
            {
                while (buf.size() >= 2)
                {
                    int sz = buf.size();
                    if (f(buf[sz - 2], buf[sz - 1]) > f(buf[sz - 1], y))
                        buf.pop_back();
                    else
                        break;
                }
                buf.push_back(y);
            }
        }
        buf.clear();
        for (int y = n-1; y >= 0; y--)
        {
            while (buf.size() >= 2 && f(buf[0], buf[1]) > 2 * y)
                buf.pop_front();
            if (arr[y][x] == '0')
                dp2[y] = LONG_MAX;
            else if (!buf.empty())
                dp2[y] = min(dp2[y], dp[buf[0]] + (buf[0] - y) * (buf[0] - y));
            
            if (dp[y] < LONG_MAX)
            {
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
        }
        dp = dp2;
    }
    long long ans = LONG_MAX;
    for (int x = 0; x < n; x++)
        ans = min(ans, dp[x]);
    printf("%lli\n", ans);
}
