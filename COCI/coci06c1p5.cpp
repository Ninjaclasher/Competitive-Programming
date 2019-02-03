#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

long double dp[1<<MAXN];

int main()
{
    int n;
    long double a;
    scanf("%i", &n);
    dp[0] = 1;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            scanf("%Lf", &a);
            for (int z = 0; z < (1<<n); z++)
                if (__builtin_popcount(z) == x && !(z>>y&1))
                    dp[z | 1<<y ] = max(dp[z | 1<<y], dp[z] * a / 100.0);
        }
    }
    printf("%.20Lf\n", dp[(1<<n)-1] * 100);
}
