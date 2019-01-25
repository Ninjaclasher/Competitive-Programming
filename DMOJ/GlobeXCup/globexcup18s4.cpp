#include <bits/stdc++.h>

using namespace std;

const int MAXN = 19;

vector<vector<int>> adj(MAXN);
int dp[MAXN][1<<MAXN];   
int n, A, B;

int solve(int u, int vis)
{
    if (~dp[u][vis])
        return dp[u][vis];
    else if (u == B)
        return dp[u][vis] = 1;
    dp[u][vis] = 0;
    for (auto &x : adj[u])
        if (!(vis>>x&1))
            dp[u][vis] |= solve(x, vis|(1<<x))<<1;
    return dp[u][vis];
}

int main()
{
    int m, a, b, v;
    memset(dp, -1, sizeof dp);
    scanf("%i%i%i%i%i", &n, &m, &A, &B, &v);
    while(m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int pos = solve(A, 1<<A), ans = INT_MAX;
    for (int x = 0; x <= n; x++)
        if ((pos>>x&1) && abs(x-v) < abs(ans-v))
            ans = x;
    assert(ans < n);
    printf("%i\n", ans);
}
