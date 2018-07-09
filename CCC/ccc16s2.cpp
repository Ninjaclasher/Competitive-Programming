#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int t, n;
    scanf("%i%i", &t, &n);
    vector<int> a(n), b(n);
    for (auto &x : a) scanf("%i", &x);
    for (auto &x : b) scanf("%i", &x);
    sort(a.begin(), a.end());
    if (!(t-1)) sort(b.begin(), b.end());
    else sort(b.rbegin(), b.rend());
    int s = 0;
    for (int x = 0; x < n; x++)
        s += max(a[x], b[x]);
    printf("%i", s);
    return 0;
}
