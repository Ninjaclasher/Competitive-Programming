#include <bits/stdc++.h>

using namespace std;

struct qqq
{
    int l, r, i;
};

int main()
{
    int n, k, q, a, b, c, d;
    scanf("%i%i%i", &n, &k, &q);
    vector<vector<qqq>> qq(51);
    vector<vector<int>> spt(20, vector<int>(200005));
    iota(spt[0].begin(), spt[0].end(), 0);
    vector<int> sz(200005);
    vector<int> ss(51);
    vector<long long> ans(100005);
    for (int x = 1; x <= n; x++)
        scanf("%i", &sz[x]);
    for (int x = 1; x <= k; x++)
        scanf("%i", &ss[x]);
    for (int x = 0; x < q; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        qq[a].push_back({b, c, x});
    }
    for (int ii = 1; ii <= k; ii++)
    {
        for (int x = 1, y = 1, cc = 0; x <= n; x++)
        {
            while (y <= n && cc+sz[y] <= ss[ii])
                cc += sz[y], y++;
            spt[0][x] = (x == y ? 0 : y);
            cc -= sz[x];
        }
        for (int x = 1; x <= 18; x++)
        {
            for (int y = 1; y <= n; y++)
            {
                if (spt[x-1][spt[x-1][y]] > n || spt[x-1][y] > n)
                    spt[x][y] = n+1;
                else
                    spt[x][y] = spt[x-1][spt[x-1][y]];
            }
        }
        for (auto &x : qq[ii])
        {
            long long cc = 0;
            for (int y = 18; y >= 0; y--)
            {
                if (!spt[y][x.l])
                    continue;
                if (spt[y][x.l] <= x.r)
                {
                    cc += 1LL<<y;
                    x.l = spt[y][x.l];
                }
            }
            if (x.l <= x.r) 
            {
                cc++;
                if (!spt[0][x.l])
                    cc = -1;
            }
            ans[x.i] = cc;
        }
    }
    for (int x = 0; x < q; x++)
        printf("%lli\n", ans[x]);
}
