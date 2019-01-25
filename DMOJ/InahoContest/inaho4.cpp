#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    long double ans = 0;
    scanf ("%i", &n);
    vector<vector<long double>> a (2, vector<long double>(n));
    for (auto &x : a)
        for (auto &y : x)
            scanf ("%Lf", &y);
    for (int x = 0; x < n; x++)
        ans += pow (a[1][x] - a [0][x], 2);
    printf ("%Lf", sqrt (ans));
    return 0;
}
