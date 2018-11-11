#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    int k;
    scanf("%lli%i", &n, &k);
    vector<pair<long long, long long>> arr(k);
    set<long long> a;
    for (auto &x : arr)
    {
        scanf("%lli%lli", &x.second, &x.first);
        a.insert(x.first);
        a.insert(x.second);
    }
    sort(arr.begin(), arr.end());
    map<long long,int> mp;
    int c = 1;
    for (auto &x : a)
        mp[x] = c++;
    vector<long long> dp(1000000);
    int i = 0;
    for (int x = 1; x < dp.size(); x++)
    {
        while (i < n && mp[arr[i].first] == x)
            dp[x] = max(dp[x], dp[mp[arr[i].second]-1] + arr[i].first-arr[i].second+1), i++;
        dp[x] = max(dp[x], dp[x-1]);
    }
    printf("%lli\n", n-dp.back());
}
