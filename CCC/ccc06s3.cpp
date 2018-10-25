#include <bits/stdc++.h>

using namespace std;

struct point
{
    long long x, y;
    friend bool operator<(point &a, point &b)
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    friend ostream &operator<<(ostream &os, point &a)
    {
        os<<a.x<<" "<<a.y;
        return os;
    }
};

static inline __attribute__((always_inline)) long long side(point &o, point &a, point &b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool intersect(vector<point> a, vector<point> b)
{
    if (max(a[0].x, a[1].x) < min(b[0].x, b[1].x)
      ||min(a[0].x, a[1].x) > max(b[0].x, b[1].x)
      ||max(a[0].y, a[1].y) < min(b[0].y, b[1].y)
      ||min(a[0].y, a[1].y) > max(b[0].y, b[1].y)      
      )
        return false;
    if (side(a[0], a[1], b[0]) * side(a[0], a[1], b[1]) > 0 || side(b[0], b[1], a[0]) * side(b[0], b[1], a[1]) > 0)
        return false;
    return true;
}

int main()
{
    point a, b;
    scanf("%lli%lli%lli%lli", &a.x, &a.y, &b.x, &b.y);
    int n, cnt = 0;
    scanf("%i", &n);
    while (n--)
    {
        int c;
        scanf("%i", &c);
        vector<point> arr(c);
        for (auto &x : arr)
            scanf("%lli%lli", &x.x, &x.y);
        for (int x = 0; x < c; x++)
            if (intersect(vector<point>{arr[(x+1)%c], arr[x]}, vector<point>{a, b}))
            {
                cnt++;
                goto nxt;
            }
        nxt:;
    } 
    printf("%i\n", cnt);
}
