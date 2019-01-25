#include <bits/stdc++.h>

using namespace std;

static inline __attribute__((always_inline)) __attribute__((const)) long long f(int x, int a, int b, int c)
{
    return (long long)a*x*x + (long long)b*x + c;
}

const int MAXT = 100020;

long long diff[4][MAXT];

int main()
{
    memset(diff, 0, sizeof(diff));
    int n, t, l, r, a, b, c;
    scanf("%i%i", &n, &t);
    assert(1 <= n && n <= 100000);
    assert(1 <= t && t <= 100000);
    while(n--)
    {
        scanf("%i%i%i%i%i", &l, &r, &a, &b, &c);
        assert(1 <= l && l <= r && r <= t);
        assert(abs(a) <= 10000);
        assert(abs(b) <= 10000);
        assert(abs(c) <= 10000);
        long long y1 = f(0, a, b, c);
        long long y2 = f(1, a, b, c);
        long long y3 = f(2, a, b, c);
        int len = r-l+1;
        long long st[3] = {
            y1,
            y2-y1,
            (y3-y2)-(y2-y1),
        };
        if (len == 1)
        {
            diff[0][l+0] +=  st[0];
            diff[0][r+1] += -st[0];
        }
        else if (len == 2)
        {
            diff[0][l+0] +=  st[0];
            diff[0][r+1] += -st[1]*(len-1) - st[0];
            diff[1][l+1] +=  st[1];
            diff[1][r+1] += -st[1];
        }
        else
        {
            diff[0][l+0] +=  st[0];
            diff[0][r+1] += -f(len-1, a, b, c);
            diff[1][l+1] +=  st[1];
            diff[1][r+1] += -st[2]*(len-2) - st[1];
            diff[2][l+2] +=  st[2];
            diff[2][r+1] += -st[2];
        }
    }
    for (int x = 2; x >= 0; x--)
        for (int y = 1; y <= t; y++)
            diff[x][y] += diff[x][y-1] + diff[x+1][y];
    for (int x = 1; x <= t; x++)
        printf("%lli%c", diff[0][x], x == t ? '\n' : ' ');
}
