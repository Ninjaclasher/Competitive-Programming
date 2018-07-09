#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, aa = 0, bb = 0, mn = 0;
    scanf("%i", &n);
    vector<int> a(n), b(n);
    for (auto &x : a)
        scanf("%i", &x);
    for (auto &x : b)
        scanf("%i", &x);
    for (int x = 0; x < n; x++)
    {
        aa += a[x], bb += b[x];
        if (aa == bb)
            mn = x+1;
    }
    if (aa == bb)
        mn = n;
    printf("%i", mn);
    return 0;
}
