#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, mi = INT_MAX;

    scanf("%i", &n);
    vector<pair<int,int>> a (n);
    for (auto &x : a)
        scanf("%i%i", &x.first, &x.second);
    for (auto &x : a)
        for (auto &y : a)
            if (x != y)
                mi = min(mi, max(abs(x.second - y.second), abs(x.first - y.first)));
    printf("%lli", mi*mi);
    return 0;
}
