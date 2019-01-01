#include <bits/stdc++.h>

using namespace std;

struct point
{
    long long x, y;
};

point scan()
{
    point a;
    scanf("%lli%lli", &a.x, &a.y);
    return a;
}

static inline __attribute__((always_inline)) long long side(point &o, point &a, point &b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

static inline __attribute__((always_inline)) bool cw(point &o, point &a, point &b)
{
    return side(o, a, b) < 0;
}

static inline __attribute__((always_inline)) bool inTriangle(vector<point> po, point a)
{
    bool aa = cw(po[0], po[1], a), bb = cw(po[1], po[2], a), cc = cw(po[2], po[0], a);
    return aa == bb && bb == cc;
}

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<point> aa(n);
    for (auto &x : aa)
        x = scan();
    point a, b, c;
    while (m--)
    {
        a = scan();
        b = scan();
        c = scan();
        long long ans = 0;
        for (auto &x : aa)
            ans += inTriangle(vector<point>{a, b, c}, x);
        printf("%lli\n", ans);
    }
}
