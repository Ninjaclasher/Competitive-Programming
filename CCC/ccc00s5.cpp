#include <bits/stdc++.h>

using namespace std;

struct point
{
    long double x, y;
};

int main()
{
    int n;
    scanf("%i", &n);
    vector<point> arr(n);
    for (auto &x : arr)
        scanf("%Lf%Lf", &x.x, &x.y);
    for (int x = 0; x < n; x++)
    {
        long double l = 0, r = 1000;
        point &a = arr[x];
        for (int y = 0; y < n; y++)
        {
            if (x == y)
                continue;
            point &b = arr[y];
            if (a.x == b.x)
            {
                if (a.y < b.y)
                    continue;
                else
                    goto nxt;
            }
            long double xx;
            long double mx = (a.x + b.x)/2, my = (a.y + b.y)/2;
            if (a.y != b.y)
            {
                long double m = -(b.x - a.x)/(b.y - a.y);
                xx = (m * mx - my) / m;
            }
            else
                xx = mx;
            if (b.x < a.x)
                l = max(l, xx);
            else
                r = min(r, xx);
        }
        if (l <= r)
            printf("The sheep at (%.2Lf, %.2Lf) might be eaten.\n", a.x, a.y);
nxt:;
    }
}
