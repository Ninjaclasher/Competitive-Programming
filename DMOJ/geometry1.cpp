#include <bits/stdc++.h>

using namespace std;

static inline double dist(long long x1, long long y1, long long x2, long long y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main() 
{
    long long n, x1, x2, x3, y1, y2, y3;
    double d1, d2, d3, p, sp;
    scanf("%lli", &n);
    while (n--)
    {
        scanf("%lli%lli%lli%lli%lli%lli", &x1, &y1, &x2, &y2, &x3, &y3);
        d1 = dist(x1, y1, x2, y2), d2 = dist(x2, y2, x3, y3), d3 = dist(x3, y3, x1, y1);
        p = d1+d2+d3;
        sp = p/2;
        printf("%.5f %.5f\n", sqrt(sp * (sp-d1) * (sp-d2) * (sp-d3)), p);
    }
    return 0;
}
