#include <bits/stdc++.h>

using namespace std;

int dp[3500][3500];
pair<int,int> par[3500][3500];

int main()
{
    string s, t;
    cin>>s>>t;
    for (int x = 1; x <= s.size(); x++)
    {
        auto ss = s[x-1];
        for (int y = 1; y <= t.size(); y++)
        {
            auto tt = t[y-1];
            if (ss == tt)
                dp[x][y] = dp[x-1][y-1] + 1, par[x][y] = make_pair(x-1, y-1);
            else
            {
                if (dp[x][y-1] > dp[x-1][y])
                    dp[x][y] = dp[x][y-1], par[x][y] = {x, y-1};
                else
                    dp[x][y] = dp[x-1][y], par[x][y] = {x-1, y};
            }
        }
    }
    string ret = "";
    pair<int,int> cur = {s.size(), t.size()};
    while (dp[cur.first][cur.second])
    {
        if (s[cur.first-1] == t[cur.second-1])
            ret += s[cur.first-1];
        cur = par[cur.first][cur.second];
    }
    reverse(ret.begin(), ret.end());
    cout<<ret<<endl;
}
