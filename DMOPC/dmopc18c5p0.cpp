#include <bits/stdc++.h>

using namespace std;

long double calc(long double a, long double b)
{
    if (a < 0.5)
        return 2 * a * b;
    else
        return 1 - 2 * (1-a) * (1-b);
}

int main()
{
    string t;
    cin>>t;
    long double ra, ga, ba, rb, gb, bb;
    cin>>ra>>ga>>ba>>rb>>gb>>bb;
    long double r, g, b;
    if (t[0] == 'M')
    {
        r = ra * rb;
        g = ga * gb;
        b = ba * bb;
    }
    else if (t[0] == 'S')
    {
        r = 1 - (1 - ra) * (1-rb);
        g = 1 - (1 - ga) * (1-gb);
        b = 1 - (1 - ba) * (1-bb);
    }
    else
    {
        r = calc(ra, rb);
        g = calc(ga, gb);
        b = calc(ba, bb);
    }
    cout<<setprecision(10)<<fixed<<r<<" "<<g<<" "<<b<<endl;
}
