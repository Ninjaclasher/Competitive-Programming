#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    scanf("%i", &n);
    assert(1 <= n && n <= 1000000);
    vector<bool> source(n+1, true);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        assert(0 <= a && a < x);
        source[a] = false;
    }
    int cnt = 0;
    for (int x = 1; x <= n; x++)
        cnt += source[x];
    printf("%i\n", cnt);
}

