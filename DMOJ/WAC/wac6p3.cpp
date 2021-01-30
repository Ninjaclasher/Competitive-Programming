#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> par(MAXN);

int find(int n)
{
    return par[n] == n ? n : par[n] = find(par[n]);
}

bool good(vector<pair<long long, int>> &arr, long long m)
{
    iota(par.begin(), par.end(), 0);
    for (int x = 1; x < arr.size(); x++)
        if (arr[x].first - arr[x - 1].first <= m)
            par[find(arr[x].second)] = find(arr[x - 1].second);
    for (int x = 0; x < arr.size(); x++)
        if (find(x) != find(arr[x].second))
            return false;
    return true;
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<long long, int>> arr(n);
    for (int x = 0; x < n; x++)
        scanf("%lli", &arr[x].first), arr[x].second = x;
    sort(arr.begin(), arr.end());
    long long l = 0, r = 1000000000000000000LL;
    while (l <= r)
    {
        long long m = l+r>>1;
        if (good(arr, m))
            r = m - 1;
        else
            l = m + 1;
    }
    printf("%lli\n", r + 1);
}
