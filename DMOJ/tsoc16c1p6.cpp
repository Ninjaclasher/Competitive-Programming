#include <bits/stdc++.h>

using namespace std;

string s, t;

int dp[1005][1005];

int run(int i, int j)
{
    if (i < 0 || j < 0)
        return 1000000;
    if (~dp[i][j])
        return dp[i][j];
    if (!i && j)
        return dp[i][j] = min(run(i, j-1), min(run(i, j-2), run(i, j-3)))+1;
    else if (!j && i)
        return dp[i][j] = min(run(i-1, j), min(run(i-2, j), run(i-3, j)))+1;
    else if (!i && !j)
        return dp[i][j] = 0;
    else if (s[i-1] != t[j-1])
        return dp[i][j] = min(
                    min(
                        min(run(i, j-1), min(run(i, j-2), run(i, j-3))),
                        min(run(i-1, j), min(run(i-2, j), run(i-3, j)))
                    ),
                    run(i-1, j-1)
                )+1;
    return dp[i][j] = run(i-1, j-1);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    scanf("%i%i", &n, &m);
    cin>>s>>t;
    printf("%i\n", run(n, m));
}
