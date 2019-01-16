#include <bits/stdc++.h>
 
using namespace std;
 
int dp[100005];
 
vector<int> a;
 
int solve(int k)
{
    if (k < 0)
        return 0;
    if (~dp[k])
        return dp[k];
    dp[k] = 1;
    for (auto &x : a)
        dp[k] &= !solve(k-x);
    return dp[k];
}
 
int main()
{
    memset(dp, -1, sizeof dp);
    int n, k;
    scanf("%i%i", &n, &k);
    a.resize(n);
    for (auto &x : a)
        scanf("%i", &x);
    printf("%s\n", solve(k) ? "Second" : "First");
}
