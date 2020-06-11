#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    int ma = 0;
    vector<int> a(n), b(n);
    for (auto &x : a)
        scanf("%i", &x);
    for (auto &x : b)
        scanf("%i", &x);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int x = 0; x < n; x++)
        ma = max(abs(a[x]-b[x]), ma);
    printf("%i\n", ma);
}
