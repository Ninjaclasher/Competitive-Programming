#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3005;

int bit[MAXN][MAXN], arr[MAXN][MAXN];

void update(int i, int j, int v)
{
    for (int x = i; x < MAXN; x += x&-x)
        for (int y = j; y < MAXN; y += y&-y)
            bit[x][y] = max(bit[x][y], v);
}

int query(int i, int j)
{
    int ret = 0;
    for (int x = i; x; x -= x&-x)
        for (int y = j; y; y -= y&-y)
            ret = max(ret, bit[x][y]);
    return ret;
}

int main()
{
    int n, k;
    long long ans = 0;
    scanf("%i%i", &n, &k);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= x; y++)
            scanf("%i", &arr[x][n-y+1]);
    for (int len = 0; len < n; len++)
    {
        for (int y = 0; y <= len; y++)
            update(n-len+y, n-y, arr[n-len+y][n-y]);
        int t = len-k+1;
        for (int y = 0; y <= t; y++)
            ans += query(n-t+y, n-y);
    }
    printf("%lli\n", ans);
}
