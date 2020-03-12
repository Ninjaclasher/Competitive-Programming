#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l;
    scanf("%i%i", &n, &l);
    l++;
    vector<long long> arr(n+1), psa(n+1), dp(n+1, LONG_MAX);
    for (int x = 1; x <= n; x++)
    {
        scanf("%lli", &arr[x]);
        psa[x] = psa[x-1] + arr[x];
    }
    dp[0] = 0;
    deque<int> buf;
    buf.push_front(0);
    auto calc = [&](int i, int j)
    {
        long long Pj = psa[j] + j;
        long long Pi = psa[i] + i;
        return (long double)(dp[j] - dp[i] + Pj * Pj - Pi * Pi) / (2.0 * (Pj - Pi));
    };
    for (int x = 1; x <= n; x++)
    {
        while (buf.size() >= 2 && calc(buf[0], buf[1]) <= psa[x] + x - l)
            buf.pop_front();
        int i = buf.front();
        long long v = (psa[x] + x - psa[i] - i - l);
        dp[x] = dp[i] + v * v;
        while (buf.size() >= 2 && calc(buf[buf.size()-2], buf[buf.size()-1]) >= calc(buf[buf.size()-1], x))
            buf.pop_back();
        buf.push_back(x);
    }
    printf("%lli\n", dp[n]);
}
