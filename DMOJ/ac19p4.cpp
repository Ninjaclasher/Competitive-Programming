#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    set<pair<int,int>> has;
    while (n--)
    {
        int x, y;
        scanf("%i%i", &x, &y);
        has.insert({x, y});
    }
    int ma = 0;
    for (auto &x : has)
    {
        for (auto &y : has)
            if (has.count({x.first, y.second}) && has.count({y.first, x.second}))
                ma = max(ma, abs(x.first - y.first) * abs(x.second - y.second));
    }
    printf("%i\n", ma);
}
