#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;

long long arr[MAXN];

long long d[MAXN][MAXN];

long long solve(int l, int r)
{
    if (~d[l][r])
        return d[l][r];
    if (l == r)
        return 0;
    if (l+1 == r)
        return d[l][r] = arr[r]-arr[l-1];
    d[l][r] = 1LL<<60;
    for (int x = l; x < r; x++)
        d[l][r] = min(d[l][r], solve(l, x) + solve(x+1, r) + arr[r]-arr[l-1]);
    return d[l][r];
}


int main()
{
    memset(d, -1, sizeof d);
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%lli", &arr[x]);
        arr[x] += arr[x-1];
    }
    printf("%lli\n", solve(1, n));
}
