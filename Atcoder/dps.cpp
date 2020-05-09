#include <bits/stdc++.h>
 
using namespace std;
 
const long long MOD = 1000000007;
 
string k;
int d;
 
long long dp[105][10005];
 
long long solve(int dig, int sum, int top)
{
    if (sum < 0)
        sum = (sum%d)+d;
    sum %= d;
    if (dig == k.size())
        return (sum == 0);
    if (top)
    {
        long long ans = 0;
        for (int x = 0; x < k[dig]-'0'; x++)
            ans += solve(dig+1, sum-x, 0);
        ans += solve(dig+1, sum-(k[dig]-'0'), 1);
        return ans%MOD;
    }
    if (~dp[sum][dig])
        return dp[sum][dig];
    dp[sum][dig] = 0;
    for (int x = 0; x < 10; x++)
        dp[sum][dig] += solve(dig+1, sum-x, 0);
    return dp[sum][dig] %= MOD;
}
 
 
int main()
{
    memset(dp, -1, sizeof dp);
    cin>>k>>d;
    printf("%lli\n", (solve(0, 0, 1)-1+MOD)%MOD);
}
