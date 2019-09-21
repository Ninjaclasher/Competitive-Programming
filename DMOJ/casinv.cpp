#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

long long solve(int n, vector<int> r, vector<int> c)
{
    sort(c.begin(), c.end());
    vector<long long> pc(n);
    pc[0] = c[0];              
    for (int x = 1; x < n; x++)
        pc[x] = pc[x-1] + c[x];
    long long ans = 0;         
    for (int x = 0; x < n; x++)
    {
        int l = upper_bound(c.begin(), c.end(), r[x]) - c.begin();
        if (l == c.size() && c[l-1] < r[x])
        {
            printf("-1\n");
            exit(0);
        }
        ans += (l ? pc[l-1] : 0) + (long long)r[x] * (n - l);
    }
    return ans;
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> c(n), r(n);
    for (auto &x : c)
        scanf("%i", &x);
    for (auto &x : r)
        scanf("%i", &x);
    solve(n, r, c);
    printf("%lli\n", solve(n, c, r));
}
