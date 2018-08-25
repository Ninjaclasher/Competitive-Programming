#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, int> mid[31];
vector<pair<int,int>> arr;

void dfs(int d, int l, int r)
{
    if (d == -1 || r < l)
        return;
    int m = r;
    for (int x = l; m == r && x <= r; x++)
        if (arr[x].first>>d&1)
            m = x-1;
    mid[d][(long long)l<<32|r] = m;
    dfs(d-1, l, m);
    dfs(d-1, m+1, r);
}

int run(int d, int v, int l, int r)
{
    if (d == -1 || l == r)
        return arr[l].second;
    int m = mid[d][(long long)l<<32|r];
    if (m == r || m == l-1)
        return run(d-1, v, l, r);
    if (v>>d&1)
        return run(d-1, v, m+1, r);
    else
        return run(d-1, v, l, m);
}

int main()
{
    int n, q, a, prev = 0;
    scanf("%i%i", &n, &q);
    arr.resize(n);
    for (int x = 0; x < n; x++)
        scanf("%i", &arr[x].first), arr[x].second = x;
    sort(arr.begin(), arr.end());
    dfs(30, 0, n-1);
    while (q--)
    {
        scanf("%i", &a);
        prev ^= a;
        printf("%i\n", run(30, prev, 0, n-1));
    }
}

