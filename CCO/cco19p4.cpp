#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int pos[MAXN], cnt[MAXN];
double dp[MAXN], po[MAXN<<1];
vector<int> buf[MAXN];
int k, n;

double poww(int x)
{
    double &v = po[x + MAXN];
    if (v > 1e-4)
        return v;
    return v = pow(x, k / 2.0);
}

static inline double g(int i, int x)
{
    return dp[i-1] + poww(x - pos[i] + 1);
}

static inline double f(int i, int j)
{
    int l = 0, r = MAXN-1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (g(i, m) > g(j, m))
            r = m-1;
        else
            l = m+1;
    }
    return r;
}

int main()
{
    int a;
    scanf("%i%i", &k, &n);
    if (k == 2)
        return 0 * printf("%i\n", n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        pos[x] = cnt[a];
        cnt[a]++;
        while (buf[a].size() >= 2 && f(buf[a][buf[a].size()-2], buf[a][buf[a].size()-1]) <= f(buf[a].back(), x))
            buf[a].pop_back();
        buf[a].push_back(x);
        while (buf[a].size() >= 2 && g(buf[a][buf[a].size()-2], pos[x]) >= g(buf[a][buf[a].size()-1], pos[x]))
            buf[a].pop_back();
        dp[x] = g(buf[a].back(), pos[x]);
    }
    printf("%.10lf\n", dp[n]);
}
