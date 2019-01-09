#include <bits/stdc++.h>

using namespace std;

map<long long,long long> mp;
vector<long long> revmp(2005);
vector<long long> arr(2005);
long long dp[2005][2005][2];
long long ma[2005][2005][2];
long long mid = 0;

long long solve(long long l, long long r, long long s)
{
    if (~dp[l][r][s])
        return dp[l][r][s];
    if (l > mid || r < mid)
        return 0;
    dp[l][r][s] = 0;
    if (s)
    {
        long long ret = solve(l, r-1, s);
        long long dist = abs(revmp[r]-revmp[r-1]);
        if (ret >= dist)
        {
            dp[l][r][s] = ret - dist + arr[r];
            ma[l][r][s] = ma[l][r-1][s] + arr[r];
        }
        
        ret = solve(l, r-1, !s);
        dist = abs(revmp[l]-revmp[r]);
        if (ret >= dist)
        {
            if (ret-dist >= dp[l][r][s])
            {
                dp[l][r][s] = ret-dist  + arr[r];
                ma[l][r][s] = ma[l][r-1][!s] + arr[r];
            }
        }
    }
    else
    {
        long long ret = solve(l+1, r, s);
        long long dist = abs(revmp[l+1]-revmp[l]);
        if (ret >= dist)
        {
            dp[l][r][s] = ret - dist + arr[l];
            ma[l][r][s] = ma[l+1][r][s] + arr[l];
        }
        ret = solve(l+1, r, !s);
        dist = abs(revmp[l]-revmp[r]);
        if (ret >= dist)
        {
            if (ret-dist >= dp[l][r][s])
            {
                dp[l][r][s] = ret-dist + arr[l];
                ma[l][r][s] = ma[l+1][r][!s] + arr[l];
            }
        }

    }
    return dp[l][r][s];
}

int main()
{
    memset(dp, -1, sizeof dp);
    long long n, a;
    scanf("%lli", &n);
    vector<pair<long long,long long>> pPos, nPos;
    for (long long x = 0; x < n; x++)
    {
        scanf("%lli", &a);
        long long d;
        scanf("%lli", &d);
        if (a < 0)
            nPos.push_back({a, d});
        else
            pPos.push_back({a, d});
    }
    sort(nPos.begin(), nPos.end());
    sort(pPos.begin(), pPos.end());
    long long c = 1;
    for (long long x = 0; x < nPos.size(); x++)
    {
        mp[nPos[x].first] = c;
        arr[c] = nPos[x].second;
        revmp[c] = nPos[x].first;
        c++;
    }
    mid = c;
    for (long long x = 0; x < pPos.size(); x++)
    {
        mp[pPos[x].first] = c;
        arr[c] = pPos[x].second;
        revmp[c] = pPos[x].first;
        c++;
    }
    dp[mid][mid][0] = dp[mid][mid][1] = ma[mid][mid][1] = ma[mid][mid][0] = arr[mid];
    long long mm = 0;
    for (long long t = 0; t < 2; t++)
    {
        for (long long x = 1; x < c; x++)
        {
            for (long long y = 1; y < c; y++)
            {
                solve(x, y, t);
                mm = max(mm, ma[x][y][t]);
            }
        }
    }
    cout<<mm<<endl;
    return 0;
}
