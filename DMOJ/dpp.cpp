#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

const int MOD = 1000000007;

long long d[2][MAXN];

vector<vector<int>> ad(MAXN);

void dfs(int s, int w)
{
    d[0][s] = d[1][s] = 1;
    for (int x : ad[s])
    {
        if (x ^ w)
        {
            dfs(x, s);
            d[0][s] = (d[0][s] * (d[0][x] + d[1][x]))%MOD;
            d[1][s] = (d[1][s] * d[0][x])%MOD;
        }
    }
    d[0][s] %= MOD;
    d[1][s] %= MOD;
}


int main()
{
    int n, a, b, c;
    scanf("%i", &n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    dfs(1,1);
    printf("%lli\n", (d[0][1] + d[1][1])%MOD);
}
