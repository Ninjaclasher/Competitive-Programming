#include <bits/stdc++.h>

using namespace std;

int a, b, c;

string s, t;
int dp[1005][1005];

int run(int i, int j)
{
    if (~dp[i][j])
        return dp[i][j];
    if (!i && j)
        return dp[i][j] = run(i, j-1)+b;
    else if (i && !j)
        return dp[i][j] = run(i-1, j)+a;
    else if (!i && !j)
        return 0;
    if (s[i-1] != t[j-1])
        dp[i][j] = min(min(run(i-1, j)+a, run(i, j-1)+b), run(i-1, j-1)+c);
    else
        dp[i][j] = run(i-1, j-1);
    return dp[i][j];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%i%i%i", &a, &b, &c);
    cin>>s>>t;
    printf("%i\n", run(s.length(), t.length()));
}

