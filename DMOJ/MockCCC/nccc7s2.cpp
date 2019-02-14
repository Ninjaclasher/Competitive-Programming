#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y, x1, y1, x2, y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    double dist = 0;
    if (x1 <= x && x <= x2)
        dist = min(abs(y1-y), abs(y2-y));
    else if (y1 <= y && y <= y2)
        dist = min(abs(x1-x), abs(x2-x));
    else
    {
        long long xx = min(abs(x1-x), abs(x2-x));
        xx *= xx;
        long long yy = min(abs(y1-y), abs(y2-y));
        yy *= yy;
        dist = sqrt(xx + yy);
    }
    printf("%.3lf\n", dist);
}
