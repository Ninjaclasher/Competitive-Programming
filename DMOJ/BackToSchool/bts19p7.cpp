#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
const int MAXV = 400;

long long dp[MAXV][MAXV];
bool vis[MAXV][MAXV];

long long a, b, n;

struct state
{
    long long aa, bb;

    long double calc()
    {
        return bb * log(b) / log(a) + aa;
    }

    friend bool operator <(state x, state y)
    {
        return x.calc() > y.calc();
    }
};

bool greatern(long long x, long long y)
{
    return ((__int128)x * y >= n);
}

long long pow(long long base, long long e)
{
    long long ret = 1;
    for (; e; e >>= 1, base = (base * base) % MOD)
        if (e&1)
            ret = (ret * base) % MOD;
    return ret;
}

bool prime(int a)
{
    for (int x = 2; x * x <= a; x++)
        if (a % x == 0)
            return false;
    return true;
}

int main()
{
    int t;
    scanf("%i", &t);
    assert(t == 1 || t == 20);
    while (t--)
    {
        memset(dp, 0, sizeof dp);
        memset(vis, 0, sizeof vis);
        scanf("%lli%lli%lli", &n, &a, &b);
        assert(1 <= n && n <= 1000000000000000000LL);
        assert(1 <= a && a < b && b <= 1000000000);
        assert(prime(a));
        assert(prime(b));

        dp[0][1] = dp[1][0] = 1;
        vis[0][1] = vis[1][0] = 1;

        priority_queue<state> buf;
        buf.push({1, 1});
        long long cnt = 0, cnta = 1, cntb = 1;
        
        bool PASSN = false;

        while (!PASSN)
        {
            PASSN = false;

            assert(!buf.empty());
            state u = buf.top();
            buf.pop();

            for (int na1 = 0; na1 <= u.aa && !PASSN; na1++)
            {
                int na2 = u.aa - na1;
                if (na1 > na2)
                    continue;
                for (int nb1 = 0; nb1 <= u.bb && !PASSN; nb1++)
                {
                    int nb2 = u.bb - nb1;
                    if (na1 == na2 && nb1 > nb2)
                        continue;
                    if (na1 == na2 && nb1 == nb2)
                    {
                        if (greatern(dp[na1][nb1] / 2, dp[na1][nb1] - 1))
                            PASSN = true;
                        else
                            dp[u.aa][u.bb] += dp[na1][nb1] * (dp[na1][nb1] - 1) / 2;
                    }
                    else
                    {
                        if (greatern(dp[na1][nb1], dp[na2][nb2]))
                            PASSN = true;
                        else
                            dp[u.aa][u.bb] += dp[na1][nb1] * dp[na2][nb2];
                    }
                    if (dp[u.aa][u.bb] >= n)
                        PASSN = true;
                }
            }

            long long mult = dp[u.aa][u.bb];

            PASSN |= (cnt + dp[u.aa][u.bb] >= n);

            if (PASSN)
                mult = n - cnt;

            cnta = (cnta + u.aa * mult) % (MOD-1);
            cntb = (cntb + u.bb * mult) % (MOD-1);

            if (dp[u.aa][u.bb] == 0)
                continue;

            cnt += dp[u.aa][u.bb];

            if (!vis[u.aa+1][u.bb])
            {
                vis[u.aa+1][u.bb] = 1;
                buf.push({u.aa+1, u.bb});
            }
            if (!vis[u.aa][u.bb+1])
            {
                vis[u.aa][u.bb+1] = 1;
                buf.push({u.aa, u.bb+1});
            }
        }
        printf("%lli\n", pow(a, cnta) * pow(b, cntb) % MOD);
    }
}
