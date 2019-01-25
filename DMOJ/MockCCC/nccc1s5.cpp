#include <bits/stdc++.h>

using namespace std;

long long dp[50][50][2][2];
int arr[50];

long long solve(int l, int r, int s, int t)
{
    if (l > r)
        return s ? INT_MAX : 0;
    long long &cur = dp[l][r][s][t];
    if (~cur)
        return cur;
    long long rr = arr[r] + t;
    int ov = 0;
    if (rr == 10)
        ov = 1, rr -= 10;
    if (l == r)
    {
        if (s)
            return cur = ov ? 0 : 10-rr;
        else
            return cur = ov ? INT_MAX : 0;
    }
    if (l == r-1)
    {
        int ll = arr[l] + ov;
        int ov2 = 0;
        if (ll == 10)
            ov2 = 1, ll -= 10;
        if (s)
        {
            cur = rr;
            if (!ov2)
                cur += 10-ll;
            cur = min(cur, 10-rr + 10-(ll+1));
        }
        else
        {
            if (ov2)
                cur = INT_MAX;
            else
            {
                cur = abs(ll-rr);
                if (ll < 9)
                    cur = min(cur, 10-rr+ll+1);
            }
        }
    }
    else if (s)
    {
        if (!ov)
        {
            int cst = 10-arr[l]+rr;
            cur = min(solve(l+1, r-1, 0, 0) + cst, solve(l+1, r-1, 1, 0) + cst-1);
        }
        else
            cur = INT_MAX;
        int cst = 10-arr[l];
        if (!ov)
            cst += 10-rr;
        cur = min(cur, min(solve(l+1, r-1, 0, 1) + cst, solve(l+1, r-1, 1, 1) + cst-1));
    }
    else
    {
        if (!ov)
        {
            int cst = abs(arr[l]-rr);
            cur = solve(l+1, r-1, 0, 0) + cst;
            if (arr[l] < 9)
            {
                cst = abs(arr[l]+1-rr);
                cur = min(cur, solve(l+1, r-1, 1, 0) + cst);
            }
        }
        else
            cur = INT_MAX;
        int cst = arr[l];
        if (!ov)
            cst += 10-rr;
        cur = min(cur, min(solve(l+1, r-1, 0, 1) + cst, solve(l+1, r-1, 1, 1) + cst + 1));
    }
    return cur;
}

int main()
{
    memset(dp, -1, sizeof dp);
    string s;
    cin>>s;
    for (int x = 1; x <= s.size(); x++)
        arr[x] = s[x-1]-'0';
    long long mi = min(solve(1, s.size(), 1, 0), solve(1, s.size(), 0, 0));
    printf("%lli\n", mi);
}

