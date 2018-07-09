#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    scanf("%i", &n);
    vector<int> a(n);
    for (auto &x : a)
        scanf("%i", &x);
    sort(a.begin(), a.end());
    if (n&1)
    {
        printf("%i ", a[n/2]);
        for (int x = 1; x <= n/2; x++)
            printf("%i %i ", a[n/2 + x], a[n/2 - x]);
    }
    else
    {
        for (int x = 1; x <= n/2; x++)
            printf("%i %i ", a[n/2 - x], a[n/2 + x - 1]);
    }
    return 0;
}
