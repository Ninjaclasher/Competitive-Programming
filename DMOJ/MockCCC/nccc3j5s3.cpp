#include <bits/stdc++.h>

using namespace std;

struct point
{
    long long x, y;
};

long double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}

long double sq(long double x)
{
    return x*x;
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<point> arr(n);
    for (auto &x : arr)
        scanf("%lli%lli", &x.x, &x.y);
    long double ans = 0;
    for (auto &x : arr)
        for (auto &y : arr)
            ans = max(ans, dist(x, y));
    for (int x = 0; x < n; x++)
    {
        for (int y = x+1; y < n; y++)
        {
            for (int z = y+1; z < n; z++)
            {
                long double a = dist(arr[x], arr[y]);
                long double b = dist(arr[y], arr[z]);
                long double c = dist(arr[z], arr[x]);
                long double s = (a + b + c) /2.0;
                if (sq(a) + sq(b) - sq(c) < 0 || sq(b) + sq(c) - sq(a) < 0 || sq(c) + sq(a) - sq(b) < 0 || s == 0)
                    ans = max(ans, max(max(a, b), c));
                else
                    ans = max(ans, 2 * a * b * c / (4 * sqrt(s * (s-a) * (s-b) * (s-c))));
            }
        }
    }
    printf("%.10Lf\n", ans/2);
}
