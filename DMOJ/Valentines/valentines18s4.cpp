#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

const long long MOD = 1000000007;

vector<long long> fact(MAXN);
vector<vector<int>> adj(MAXN);

long long dfs(int u)
{
    long long ans = fact[adj[u].size()+1];
    for (auto &x : adj[u])
        ans = (ans * dfs(x))%MOD;
    return ans;
}

int main()
{
    int n, a;
    fact[0] = fact[1] = 1;
    for (int x = 2; x < MAXN; x++)
        fact[x] = fact[x-1] * x % MOD;
    scanf("%i", &n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i", &a);
        adj[a].push_back(x);
    }
    cout<<dfs(0)<<endl;
}
