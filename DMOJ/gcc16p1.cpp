#include <bits/stdc++.h>

using namespace std;

struct ev
{
    int x, t, i;
    friend bool operator<(ev &a, ev &b)
    {
        return a.x < b.x;
    }
};

int main()
{
    int n, a, c, l, r;
    long long s = 0;
    scanf("%i%i%i", &n, &a, &c);
    vector<ev> ee;
    vector<int> cur(2);
    while (a--)
    {
        scanf("%i%i", &l, &r);
        ee.push_back({l, 1, 0});
        ee.push_back({r+1, -1, 0});
    }
    while (c--)
    {
        scanf("%i%i", &l, &r);
        ee.push_back({l, 1, 1});
        ee.push_back({r+1, -1, 1});
    }
    ee.push_back({n, 0, 0});
    sort(ee.begin(), ee.end());
    for (int x = 0; x < ee.size(); x++)
    {
        cur[ee[x].i] += ee[x].t;
        if (cur[0] && !cur[1])
            s += ee[x+1].x - ee[x].x;
    }
    printf("%lli", s);
}
