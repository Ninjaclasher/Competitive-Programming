#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

vector<int> tpsa(MAXN), fpsa(MAXN);
vector<int> dp(MAXN, INT_MAX);

int main()
{
    int n, s;
    scanf("%i%i", &n, &s);
    vector<pair<int,int>> arr(n);
    for (auto &x : arr)
        scanf("%i%i", &x.first, &x.second);
    reverse(arr.begin(), arr.end());
    for (int x = 1; x <= n; x++)
    {
        tpsa[x] = tpsa[x-1] + arr[x-1].first;
        fpsa[x] = fpsa[x-1] + arr[x-1].second;
    }
    dp[0] = 0;
    deque<int> buf;
    buf.push_back(0);
    auto f = [&](int i, int j)
    {
        return (long double)(dp[i] - dp[j]) / (tpsa[i] - tpsa[j]);
    };
    for (int x = 1; x <= n; x++)
    {
        while (buf.size() >= 2 && f(buf[0], buf[1]) < fpsa[x])
            buf.pop_front();
        dp[x] = dp[buf[0]] + (s + tpsa[x] - tpsa[buf[0]]) * fpsa[x];
        while (buf.size() >= 2)
        {
            int sz = buf.size();
            if (f(buf[sz - 2], buf[sz - 1]) > f(buf[sz - 1], x))
                buf.pop_back();
            else
                break;
        }
        buf.push_back(x);
    }
    printf("%i\n", dp[n]);
}
