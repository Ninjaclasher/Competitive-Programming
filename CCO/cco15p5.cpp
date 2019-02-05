#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105, MAXD = 14;

struct no
{
    int p, t;
} arr[MAXN];

long double dp[MAXN][MAXD][MAXD][MAXD][MAXD];

int n, d;

long double solve(int i, int aa, int bb, int cc, int dd)
{
    if (i == n)
        return INT_MAX;
    long double &cur = dp[i][aa][bb][cc][dd];
    if (cur >= 0)
        return cur;
    int k[4];
    int ccc [4] = {aa, bb, cc, dd};
    cur = 0;
    for (k[0] = 1; k[0] <= 12; k[0]++)
    {
        for (k[1] = k[0]; k[1] <= 12; k[1]++)
        {
            if (k[0] == k[1] && d > 1)
                continue;
            for (k[2] = k[1]; k[2] <= 12; k[2]++)
            {
                if (k[1] == k[2] && d > 2)
                    continue;
                for (k[3] = k[2]; k[3] <= 12; k[3]++)
                {
                    if (k[2] == k[3] && d > 3)
                        continue;
                    bool good = false;
                    int cnt = 0;
                    for (int x = 0; x < d; x++)
                    {
                        cnt += (k[x] != ccc[x]);
                        good |= (k[x] == arr[i+1].p);
                    }
                    if (good)
                    {
                        long double ret = solve(i+1, k[0], k[1], k[2], k[3]);
                        if (cnt)
                            ret = min(ret, (long double)(arr[i+1].t - arr[i].t) / cnt);
                        cur = max(cur, ret);
                    }
                }
            }
        }
    }
    return cur;
}

int main()
{
    for (int x = 0; x < MAXN; x++)
        for (int aa = 0; aa < MAXD; aa++)
            for (int bb = 0; bb < MAXD; bb++)
                for (int cc = 0; cc < MAXD; cc++)
                    for (int dd = 0; dd < MAXD; dd++)
                        dp[x][aa][bb][cc][dd] = -1;
    scanf("%i%i", &n, &d);
    for (int x = 1; x <= n; x++)
        scanf("%i%i", &arr[x].t, &arr[x].p);
    int k[4];
    long double ans = 0;
    for (k[0] = 1; k[0] <= 12; k[0]++)
    {
        for (k[1] = k[0]; k[1] <= 12; k[1]++)
        {
            if (k[0] == k[1] && d > 1)
                continue;
            for (k[2] = k[1]; k[2] <= 12; k[2]++)
            {
                if (k[1] == k[2] && d > 2)
                    continue;
                for (k[3] = k[2]; k[3] <= 12; k[3]++)
                {
                    if (k[2] == k[3] && d > 3)
                        continue;
                    bool good = false;
                    for (int x = 0; x < d; x++)
                        good |= (k[x] == arr[1].p);
                    if (good)
                        ans = max(ans, solve(1, k[0], k[1], k[2], k[3]));
                }
            }
        }
    }
    printf("%.2Lf\n", ans == INT_MAX ? 0 : ans);
;}
