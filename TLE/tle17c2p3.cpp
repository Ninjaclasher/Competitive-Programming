#include <bits/stdc++.h>

using namespace std;

inline double distance(int x, int y, int x2, int y2) { return sqrt(pow(x2-x, 2)+pow(y2-y, 2)); }

inline double speed(int a, int b, int v, double dist) { return (v*(b-a))/dist; }

int main()
{
    int n, r, a, b, c, d, e;
    scanf("%i%i%i%i%i%i%i", &n, &r, &a, &b, &c, &d, &e);
    r*=r;
    double wixx = a, wiyy = b, wicx = speed(a,c,e,distance(a,b,c,d)), wicy = speed(b,d,e,distance(a,b,c,d));
    for (int x = 2; x <= n; x++)
    {
        scanf("%i%i%i%i%i", &a, &b, &c, &d, &e);
        double xP = wixx - a, xV = wicx - speed(a,c,e,distance(a,b,c,d));
        double yP = wiyy - b, yV = wicy - speed(b,d,e,distance(a,b,c,d));
        double A = xV*xV + yV*yV, B = 2*(xP*xV + yP*yV), C = xP*xP + yP*yP, T = 0.0;
        if (A) T = max(-B / (2*A), 0.0);
        double dist = A*T*T + B*T + C;
        if (dist <= r)
            printf("%i\n", x);
    }
}
