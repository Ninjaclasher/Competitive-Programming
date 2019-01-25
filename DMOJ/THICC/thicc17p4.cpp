#include <bits/stdc++.h>

using namespace std;

double fin = 0x3F3F3F;

int next(string str1, string str2, int m, int n)
{
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    for (int x = 0; x <= m; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            if (!x) dp[x][y] = y;
            else if (!y) dp[x][y] = x;
            else if (str1[x-1] == str2[y-1]) dp[x][y] = dp[x-1][y-1];
            else dp[x][y] = 1 + min(min(dp[x][y-1], dp[x-1][y]), dp[x-1][y-1]);
        }
    }

    return dp[m][n];   
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string cor, s;
    int n, t;
    cin>>cor>>n;
    while (n--)
    {
        double acur = 0;
        cin>>t;
        for (int x = 0; x < t; x++)
        {
            cin>>s;
            if (acur/t < fin)
                acur += next(cor, s, cor.length(), s.length());
        }
        acur /= t;
        fin = min(fin, acur);
    }
    printf("%.8f", fin);
    return 0;
}
