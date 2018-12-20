#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<int> dp(1<<20);
int n;

int solve(int msk)
{
    if (~dp[msk])
        return dp[msk];
    vector<int> avail, unavail;
    for (int x = 0; x < n; x++)
    {
        if (msk>>x&1)
            avail.push_back(x);
        else
            unavail.push_back(x);
    }
    if (avail.empty())
        return dp[msk] = 0;
    else if (avail.size() == 1)
        return dp[msk] = arr[avail[0]];
    else if (avail.size() == 2)
        return dp[msk] = arr[avail[1]];
    dp[msk] = INT_MAX;
    for (int x = 0; x < avail.size()-1; x++)
    {
        int mi = avail[x];
        if (!unavail.empty() && arr[avail[x]] > arr[unavail[0]])
            mi = unavail[0];
        dp[msk] = min(dp[msk],
                    solve(msk^(1<<mi)^(1<<avail[x])^(1<<avail[x+1])) + arr[mi] + arr[avail[x+1]]
                );
    }
    return dp[msk];
}

int main()
{
    fill(dp.begin(), dp.end(), -1);
    scanf("%i", &n);
    arr.resize(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    printf("%i\n", solve((1<<n)-1));
}
