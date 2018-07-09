#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    long long t = 0;
    scanf("%i", &n);
    vector<long long> a(n), b(n);
    while (n--)
        scanf("%i", &a[n]), b[n] = a[n];
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    for (int x = 0; x < a.size(); x++)
        t += a[x]*b[x], t %=10007;
    printf("%lli", t);
    return 0;
}
