#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a, b;
    scanf("%i%i%i", &n, &a, &b);
    vector<vector<int>> adj(n+1);
    while (a || b)
    {
        adj[b].push_back(a);
        scanf("%i%i", &a, &b);
    }
    vector<int> dp(n+1);
    dp[1] = 1;
    for (int x = 2; x <= n; x++)
        for (auto &y : adj[x])
            dp[x] += dp[y];
    printf("%i", dp[n]);
    return 0;
}
