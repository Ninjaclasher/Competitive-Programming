#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> dp(16, vector<long long>(140, -1));
vector<long long> po10(17, 1);
long long a, b, s, mmi = -1;

long long next(long long pre, long long dig, long long sum)
{
    if (sum < 0) return 0;
    long long mi = pre, ma = pre + po10[dig]-1;
    if (mi > b || ma < a) return 0;
    if (!dig)
    {
        if (sum) return 0;
        if (mmi == -1) 
            mmi = pre;
        return 1;
    }
    bool inRange = (mi >= a && ma <= b);
    if (inRange && dp[dig][sum] != -1) return dp[dig][sum];
    long long ans = 0;
    for (int x = 0; x < 10; x++)
        ans += next(pre + x*po10[dig-1], dig-1, sum - x);
    if (inRange) return dp[dig][sum] = ans;
    else return ans;
}

int main()
{
    for (int x = 1; x < po10.size(); po10[x] = po10[x-1]*10, x++);
    scanf("%lli%lli%lli", &a, &b, &s);
    long long ans = next(0, 15, s);
    printf("%lli\n%lli", ans, mmi);
}
