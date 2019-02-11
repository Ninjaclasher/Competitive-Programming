#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);

struct point
{
    int x, y;
};

struct bunny : point
{
    int w;
};

static inline long double ang(point a, point o)
{
    int yy = a.y-o.y;
    int xx = a.x-o.x;
    int g = abs(__gcd(xx, yy));
    return atan2(yy/g, xx/g);
}

static inline bool eq(long double a, long double b)
{
    return abs(a-b) < 1e-9;
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<bunny> arr(n);
    for (auto &x : arr)
        scanf("%i%i%i", &x.x, &x.y, &x.w);
    int ans = 0;
    for (int z = 0; z < n; z++)
    {
        map<long double, int> mp;
        int sum = 0;
        for (int y = 0; y < n; y++)
        {
            if (z == y)
                continue;
            sum += arr[y].w;
            mp[ang(arr[y], arr[z])] += arr[y].w;
        }
        vector<pair<long double,int>> cur(mp.size()*2);
        int cc = 0;
        for (auto &x : mp)
            cur[cc++] = x;
        for (auto &x : mp)
        {
            cur[cc] = x;
            cur[cc].first += 2*PI;
            cc++;
        }
        int sz = mp.size();
        int curs = 0;
        for (int x = 0, y = 0; x < sz; x++)
        {
            long double VV = cur[x].first + PI;
            while (y < cur.size() && cur[y].first < VV)
            {
                curs += cur[y].second;
                y++;
            }
            ans = max(ans, max(sum-curs + arr[z].w, arr[z].w + curs + eq(cur[y].first, VV)*cur[y].second));
            curs -= cur[x].second;
        }
    }
    printf("%i\n", ans);
}
