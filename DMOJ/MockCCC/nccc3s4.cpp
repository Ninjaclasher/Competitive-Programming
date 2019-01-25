#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    long long s = 0, a, b = 0;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%lli", &a);
        s += a, b = max(b, a);
    }
    printf("%s", b*2 <= s && !(s&1) ? "YES\n" : "NO\n");
    return 0;
}
