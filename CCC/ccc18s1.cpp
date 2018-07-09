#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> a(n);
    for (auto &x : a)
        scanf("%i", &x);
    double mi = INT_MAX;
    sort(a.begin(), a.end());
    for (int x = 1; x < n-1; x++)
        mi = min(mi, abs(a[x]-a[x-1])/2.0 + abs(a[x+1]-a[x])/2.0);
    printf("%.1lf", mi);
}
