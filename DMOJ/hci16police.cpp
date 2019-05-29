#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

long long dp[MAXN], arr[MAXN];

int main()
{
    int n, h;
    scanf("%i%i", &n, &h);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]);
    int prev = 0;
    for (int x = 1; x <= n; x++)
    {
        dp[x] = LONG_MAX;
        for (int y = prev; y < x; y++)
        {
            long long k = dp[y] + (arr[x]-arr[y+1])*(arr[x]-arr[y+1]) + h;
            if (k < dp[x])
            {
                dp[x] = k;
                prev = y;
            }
        }
    }
    cout << dp[n] << endl;
}
