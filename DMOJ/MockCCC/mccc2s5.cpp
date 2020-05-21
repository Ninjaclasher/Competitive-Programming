#include <bits/stdc++.h>

using namespace std;

long long a, b, acnt, bcnt, neededspace, atot, calc;

struct tube
{
    long long space = 0, freespace = 0, typea = 0, typeb = 0;
    bool timesb4disc;
    tube(long long size)
    {
        space = size;
        typea = space/a;
        freespace = space - typea * a;
        atot += typea;
        update();
    }
    void update()
    {
        freespace = space - typea * a - typeb * b;
        timesb4disc = ceil((long double)(neededspace - freespace) / calc + 1) * (b / a + 1) - 1 <= typea;
    }
    friend bool operator <(tube x, tube y)
    {
        return x.freespace < y.freespace;
    }
};


void do_dp(int m)
{
    vector<vector<long long>> dp(2, vector<long long>(acnt+5, LONG_MIN));
    dp[0][0] = 0;
    int ans = 0, l;
    for (int x = 1; x <= m; x++)
    {
        scanf("%i", &l);
        for (int y = 0; y <= acnt; y++)
        {
            dp[x&1][y] = LONG_MIN;
            for (int add = 0; add <= y && (long long)add * a <= l; add++)
                if (dp[x&1^1][y-add] > LONG_MIN)
                    dp[x&1][y] = max(dp[x&1][y], dp[x&1^1][y - add] + (l - add  * a) / b);
            if (dp[x&1][y] > LONG_MIN)
                ans = max(ans, y + (int)min((long long)bcnt, dp[x&1][y]));
        }
    }
    printf("%i\n", ans);
    exit(0);
}


int main()
{
    int m;
    scanf("%lli%lli%lli%lli%i", &a, &acnt, &b, &bcnt, &m);
    if (acnt * acnt * m <= 100000000)
        do_dp(m);
    priority_queue<tube> buf;
    queue<tube> q1, q2;
    neededspace = b - (b / a) * a;
    calc = (b / a + 1) * a - b;
    while (m--)
    {
        long long l;
        scanf("%lli", &l);
        tube x = tube(l);
        if (x.freespace >= neededspace && x.space >= b)
            q1.push(x);
        else if (x.space >= b)
        {
            if (x.timesb4disc)
                buf.push(x);
            else
                q2.push(x);
        }
    }
    long long badded = 0;
    while (acnt < atot && badded < bcnt)
    {
        if (!q1.empty())
        {
            tube cur = q1.front();
            q1.pop();
            if (atot - b/a >= acnt)
            {
                badded++;
                atot -= b/a;
                cur.typeb++;
                cur.typea -= b/a;
                cur.update();
                if (cur.typea * a + cur.freespace >= b)
                {
                    if (!cur.timesb4disc)
                        q2.push(cur);
                    else if (cur.freespace >= neededspace)
                        q1.push(cur);
                    else
                        buf.push(cur);
                }
            }
        }
        else if (!buf.empty())
        {
            tube cur = buf.top();
            buf.pop();
            if (atot - (b/a + 1) >= acnt)
            {
                atot -= b/a + 1;
                badded++;
                cur.typeb++;
                cur.typea -= b/a + 1;
                cur.update();
                if (cur.typea * a + cur.freespace >= b)
                {
                    if (!cur.timesb4disc)
                        q2.push(cur);
                    else if (cur.freespace >= neededspace)
                        q1.push(cur);
                    else
                        buf.push(cur);
                }
            }
        }
        else if (!q2.empty())
        {
            tube cur = q2.front();
            q2.pop();
            if (atot - (b/a + 1) >= acnt)
            {
                atot -= b/a + 1;
                badded++;
                cur.typeb++;
                cur.typea -= b/a+1;
                cur.update();
                if (cur.typea * a + cur.freespace >= b)
                    q2.push(cur);
            }
        }
        else
            break;
    }
    printf("%lli\n", min(acnt, atot) + badded);
}
