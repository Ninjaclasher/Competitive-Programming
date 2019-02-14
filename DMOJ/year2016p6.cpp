#include <bits/stdc++.h>

using namespace std;

int dp[2][1<<10][1<<10];
int a1[10], a2[10];

int w, l, r;

int solve(int lmsk, int rmsk, int t, int w1, int w2)
{
    if (abs(w1-w2) > w)
        return INT_MAX/2;
    int &cur = dp[t][lmsk][rmsk];
    if (~cur)
        return cur;
    if (lmsk == (1<<l)-1 && rmsk ==(1<<r)-1)
        return cur = 0;
    cur = INT_MAX/2;
    for (int x = 0; x < l; x++)
        if (!(lmsk>>x&1))
            cur = min(cur, solve(lmsk ^ (1<<x), rmsk, 0, w1-a1[x], w2) + (t != 0));
    for (int x = 0; x < r; x++)
        if(!(rmsk>>x&1))
            cur = min(cur, solve(lmsk, rmsk ^ (1<<x), 1, w1, w2-a2[x]) + (t != 1));
    return cur;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%i%i%i", &l, &r, &w);
    int s1 = 0, s2 = 0;
    for (int x = 0; x < l; x++)
        scanf("%i", &a1[x]), s1 += a1[x];
    for (int x = 0; x < r; x++)
        scanf("%i", &a2[x]), s2 += a2[x];
    printf("%i\n", min(solve(0, 0, 0, s1, s2), solve(0, 0, 1, s1, s2))+1);
}
