#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> dp[11][20];

string cc;

long long calc(int dig, int len)
{
    return (long long)dig * len * len;
}

pair<long long, long long> solve(int prev, int i, int top, bool nonZero = false)
{
    if (i == cc.size())
        return {0, 1};
    if (top)
    {
        long long ans = 0, cnt = 0;
        auto tmp = solve(0, i+1, cc[i] == 0, nonZero);
        ans += tmp.first;
        cnt += tmp.second;
        for (int x = i; x < cc.size(); x++)
        {
            for (int y = 1; y < 10; y++)
            {
                if (y == prev)
                    continue;
                bool ttop = true;
                for (int z = i; z <= x && ttop; z++)
                {
                    if (y > cc[z])
                        goto fail;
                    else if (y < cc[z])
                        ttop = false;
                }
                auto tmp = solve(y, x+1, ttop, 1);
                ans += calc(y, x-i+1) * tmp.second + tmp.first;
                cnt += tmp.second;
            }
fail:;
        }
        return {ans, cnt};
    }
    auto &cur = dp[prev][i];
    if (~cur.first)
        return cur;
    cur = {0, 0};
    auto tmp = solve(0, i+1, 0, nonZero);
    cur.first += tmp.first;
    cur.second += tmp.second;
    for (int x = i; x < cc.size(); x++)
    {
        for (int y = 1; y < 10; y++)
        {
            if (y == prev)
                continue;
            auto tmp = solve(y, x+1, 0, 1);
            cur.first += calc(y, x-i+1) * tmp.second + tmp.first;
            cur.second += tmp.second;
        }
    }
    return cur;
}

void init()
{
    for (auto &x : cc)
        x -= '0';
    memset(dp, -1, sizeof dp);
}

int main()
{
    long long a, b;
    scanf("%lli%lli", &a, &b);
    cc = to_string(b);
    init();
    long long ans = solve(10, 0, 1).first;
    cc = to_string(a-1);
    init();
    ans -= solve(10, 0, 1).first;
    printf("%lli\n", ans);
}
