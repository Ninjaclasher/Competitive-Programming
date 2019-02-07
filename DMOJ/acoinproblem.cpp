#include <bits/stdc++.h>

using namespace std;

vector<int> dp(10005, INT_MAX);

struct query
{
    int c, l, i;
    friend bool operator<(query a, query b)
    {
        return a.l < b.l;
    }
};

int main()
{
    int n, v;
    scanf("%i%i", &n, &v);
    vector<int> arr(n+1);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    vector<query> qu(v);
    vector<int> ans(v);
    for (int x = 0; x < v; x++)
    {
        scanf("%i%i", &qu[x].c, &qu[x].l);
        qu[x].i = x;
    }
    sort(qu.begin(), qu.end());
    dp[0] = 0;
    for (int i = 0, x = 1; x <= n; x++)
    {
        for (int y = arr[x]; y < 10005; y++)
            if (dp[y-arr[x]] < INT_MAX)
                dp[y] = min(dp[y], dp[y-arr[x]] + 1);
        while (i < v && qu[i].l == x)
            ans[qu[i].i] = dp[qu[i].c], ++i;
    }
    for (auto &x : ans)
        printf("%i\n", x == INT_MAX ? -1 : x);
}
