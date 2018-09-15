#include <bits/stdc++.h>

using namespace std;

struct nd
{
    long long d;
    long double aa;
    friend bool operator<(nd a, nd b)
    {
        return a.aa < b.aa || (a.aa == b.aa && a.d < b.d);
    }
};

int main()
{
    long long n, c, a, b;
    scanf("%lli%lli", &n, &c);
    vector<nd> po(n);
    for (auto &x : po)
    {
        scanf("%lli%lli%lli", &x.d, &a, &b);
        x.aa = sqrt(a*a+b*b);
    }
    long long sum = 0;
    long double ma = 0;
    sort(po.begin(), po.end());
    for (int x = 0; x < n; x++)
    {
        sum += po[x].d;
        if (sum-c*po[x].aa*po[x].aa > ma)
            ma = sum-c*po[x].aa*po[x].aa;
    }
    printf("%.0Lf\n", ma);
}
