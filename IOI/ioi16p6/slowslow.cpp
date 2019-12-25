#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

vector<pair<int,int>> points;
int nn;

long long sq(long long v)
{
    return v * v;
}

long long calc(int i, int j)
{
    return max(0LL, sq(points[j].second - points[i].first + 1) - (i ? sq(max(0, points[i-1].second - points[i].first + 1)) : 0));
}

long long take_photos(int n, int m, int k, int *r, int *c)
{
    vector<pair<int,int>> tmp(n);
    for (int x = 0; x < n; x++)
    {
        if (r[x] >= c[x])
            swap(r[x], c[x]);
        tmp[x] = make_pair(r[x], c[x]);
    }
    sort(tmp.begin(), tmp.end(), cmp);
    for (auto &x : tmp)
    {
        if (!points.empty() && points.back().first <= x.first && points.back().second >= x.second)
            continue;
        points.push_back(x);
    }
    nn = points.size();
    vector<vector<long long>> dp(nn, vector<long long>(k+1, LONG_MAX));
    for (int y = 1; y <= k; y++)
    {
        for (int x = 0; x < nn; x++)
        {
            dp[x][y] = min(dp[x][y-1], calc(0, x));
            if (y > 1)
                for (int z = 0; z < nn; z++)
                    dp[x][y] = min(dp[x][y], dp[z][y-1] + calc(z + 1, x));
        }
    }
    return dp[nn-1][k];
}

int main()
{
    int n, m, k;
    scanf("%i%i%i", &n, &m, &k);
    int r[n], c[n];
    for (int x = 0; x < n; x++)
        scanf("%i%i", &r[x], &c[x]);
    printf("%lli\n", take_photos(n, m, k, r, c));
}
