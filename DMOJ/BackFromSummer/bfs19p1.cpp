#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, ma = INT_MAX, mai = 0, a, c;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        c = 0;
        for (int y = 1; y <= m; y++)
        {
            scanf("%i", &a);
            c += (a == 1 || a == 10);
        }
        if (c < ma)
            ma = c, mai = x;
    }
    printf("%i\n", mai);
}
