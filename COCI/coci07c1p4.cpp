#include <bits/stdc++.h>

using namespace std;

long long dp[300][300];
string aa, format = "%lli\n";
const int mod = 100000;

static inline __attribute__((always_inline)) char open(char c){return c == '(' || c == '{' || c == '[';}
static inline __attribute__((always_inline)) char close(char c){return c == ')' || c == '}' || c == ']';}
static inline __attribute__((always_inline)) char opposite(char c)
{
    if (close(c))
        return '\0';
    if (c == '(') return ')';
    else if (c == '{') return '}';
    else if (c == '[') return ']';
    abort();
}

long long solve(int l, int r)
{
    if (l >= r)
        return 1;
    else if (~dp[l][r])
        return dp[l][r];
    dp[l][r] = 0;
    for (int x = l+1; x <= r; x += 2)
    {
        if (close(aa[l]) || open(aa[x]))
            continue;
        else if (aa[l] == '?' && aa[x] == '?')
            dp[l][r] += (long long)3*solve(l+1, x-1)*solve(x+1, r);
        else if (aa[l] == '?' || aa[x] == '?' || opposite(aa[l]) == aa[x])
            dp[l][r] += (long long)solve(l+1, x-1)*solve(x+1, r);
    }
    if (dp[l][r] > mod)
        dp[l][r] %= mod, format = "%05lli\n";
    return dp[l][r];
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    scanf("%i", &n);
    cin>>aa;
    printf(format.c_str(), solve(0, n-1));
}

