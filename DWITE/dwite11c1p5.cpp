#include <bits/stdc++.h>

using namespace std;

int dp[300][300];

bool palindrome(string a)
{
    for (int x = 0; x < a.size()/2; x++)
        if (a[x] != a[a.size()-x-1])
            return false;
    return true;
}

string t;

int solve(int l, int r)
{
    if (~dp[l][r])
        return dp[l][r];
    int &cc = dp[l][r];
    if (palindrome(t.substr(l, r-l+1)))
        return cc = 0;
    if (l == r)
        return cc = 0;
    return cc = min(
                solve(l+1, r) + 1,
                min(
                    solve(l, r-1) + 1,
                    solve(l+1, r-1) + 2*(t[l] != t[r])
                    )
            );
}

int main()
{
    for (int x = 0; x < 5; x++)
    {
        memset(dp, -1, sizeof dp);
        cin>>t;
        cout<<t.size()-solve(0, t.size()-1)<<"\n";
    }
}
