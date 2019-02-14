#include <bits/stdc++.h>

using namespace std;

struct point
{
    int x, y;
};

int shoelace(point a, point b, point c)
{
    return abs(a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x);
}

point scan()
{
    point a;
    scanf("%i%i", &a.x, &a.y);
    return a;
}

int main()
{
    point a = scan();
    point b = scan();
    point c = scan();
    int area = shoelace(a, b, c);
    int n;
    scanf("%i", &n);
    int ans = 0;
    while (n--)
    {
        point d = scan();
        if (area == shoelace(a, b, d) + shoelace(b, c, d) + shoelace(a, c, d))
            ans++;
    }
    printf("%i.%i\n%i\n", area>>1, area&1 ? 5 : 0, ans);
}
