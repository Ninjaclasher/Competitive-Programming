#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, cc = 0;
    scanf("%i%i", &n, &t);
    int c[n];
    for (auto &x : c)
        scanf("%i", &x);
    for (int x = 0; x < (1<<n); x++)
    {
        int s = 0;
        for (int y = 0; y < n; y++)
            if ((x>>y)&1)
                s += c[y];
        cc += s == t;
    }
    printf("%i", cc);
}
