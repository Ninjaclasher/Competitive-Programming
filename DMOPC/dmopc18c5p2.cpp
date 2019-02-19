#include <bits/stdc++.h>

using namespace std;

long double EPS = 1e-7;

int main()
{
    int n, m;
    long double s = 0;
    scanf("%i%i", &n, &m);
    vector<vector<long double>> arr(n, vector<long double>(m));
    for (auto &x : arr)
        for (auto &y : x)
            scanf("%Lf", &y), s += y;
    s /= n * m;
    if (s+EPS < 0.48)
        printf("underexposed\n");
    else if (abs(s-0.48) < EPS)
        return 0 * printf("correctly exposed\n");
    else
        printf("overexposed\n");
    long double l = 0, r = 100;
    while (r-l > EPS)
    {
        long double mid = (l+r)/2;
        long double ss = 0;
        for (auto &x : arr)
            for (auto &y : x)
                ss += min((long double)1, y*mid);
        ss /= n*m;
        if (ss+EPS < 0.48)
            l = mid+EPS;
        else if (abs(ss-0.48) < EPS)
            return 0 * printf("%.10Lf\n", mid);
        else
            r = mid-EPS;
    }
}
