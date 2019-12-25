#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

long long h[MAXN], dp[MAXN];

long double f(int i, int j)
{
    return (dp[i] - dp[j] + h[i]*h[i] - h[j]*h[j]) / (2.0 * (h[i]-h[j]));
}

int main()
{
    int n;
    long long c;
    scanf("%i%lli", &n, &c);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &h[x]);
    deque<int> buf;
    buf.push_back(1);
    for (int x = 2; x <= n; x++)
    {
        while (buf.size() >= 2 && f(buf[0], buf[1]) <= h[x])
            buf.pop_front();
        dp[x] = dp[buf.front()] + (h[x] - h[buf.front()]) * (h[x] - h[buf.front()]) + c;
        while (buf.size() >= 2 && f(buf[buf.size()-2], buf[buf.size()-1]) >= f(buf[buf.size()-1], x))
            buf.pop_back();
        buf.push_back(x);
    }
    printf("%lli\n", dp[n]);
}
