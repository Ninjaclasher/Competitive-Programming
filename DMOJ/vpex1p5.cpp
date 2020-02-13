#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
const int MAXT = 105;

int dp[MAXT][MAXN];
vector<pair<int,int>> arr(MAXN);

struct query
{
    int l, r, t;
};

long long ans = 0;

void run(int l, int r, vector<query> &cc)
{
    if (l == r)
    {
        for (auto &x : cc)
            if (x.t >= arr[l].first)
                ans += arr[l].second;
        return;
    }
    int m = l+r>>1;
    vector<query> ll, rr;
    for (int y = 0; y < MAXT; y++)
        dp[y][m] = dp[y][m+1] = 0;
    for (int y = arr[m].first; y < MAXT; y++)
        dp[y][m] = arr[m].second;
    for (int y = arr[m+1].first; y < MAXT; y++)
        dp[y][m+1] = arr[m+1].second;
    for (int x = m-1; x >= l; x--)
    {
        for (int y = 0; y < MAXT; y++)
            dp[y][x] = dp[y][x+1];
        for (int y = arr[x].first; y < MAXT; y++)
            dp[y][x] = max(dp[y][x], dp[y-arr[x].first][x+1] + arr[x].second);
    }
    for (int x = m+2; x <= r; x++)
    {
        for (int y = 0; y < MAXT; y++)
            dp[y][x] = dp[y][x-1];
        for (int y = arr[x].first; y < MAXT; y++)
            dp[y][x] = max(dp[y][x], dp[y-arr[x].first][x-1] + arr[x].second);
    }
    for (auto &x : cc)
    {
        if (x.r <= m)
            ll.push_back(x);
        else if (x.l > m)
            rr.push_back(x);
        else
        {
            long long cur = 0;
            for (int y = 0; y <= x.t; y++)
                cur = max(cur, (long long)dp[y][x.l] + dp[x.t-y][x.r]);
            ans += cur;
        }
    }
    run(l, m, ll);
    run(m+1, r, rr);
}


int main()
{
    int n, q;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        scanf("%i%i", &arr[x].first, &arr[x].second);
    scanf("%i", &q);
    vector<query> qq(q);
    for (auto &x : qq)
        scanf("%i%i%i", &x.l, &x.r, &x.t);
    run(1, n, qq);
    printf("%lli\n", ans);
}
