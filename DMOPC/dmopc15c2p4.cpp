#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct aa
{
    long long l, r, h;
    friend bool operator<(aa &a, aa &b)
    {
        return a.r < b.r;
    }
};

int main()
{
    int n;
    scanf("%i", &n);
    vector<aa> arr(n);
    long long a, b, c;
    vector<long long> k;
    map<long long, int> mp;
    for (auto &x : arr)
    {
        scanf("%lli%lli%lli", &a, &b, &c);
        x.l = a, x.r = a+b-1, x.h = c;
        k.push_back(a);
        k.push_back(a+b-1);
    }
    sort(arr.begin(), arr.end());
    sort(k.begin(), k.end());
    k.erase(unique(k.begin(), k.end()), k.end());
    c = 1;
    for (auto &x : k)
        mp[x] = c++;
    vector<long long> dp(400000);
    int i = 0;
    for (int x = 1; x < dp.size(); x++)
    {
        while (mp[arr[i].r] == x)
            dp[x] = max(dp[x], dp[mp[arr[i].l]-1] + arr[i].h), i++;
        dp[x] = max(dp[x], dp[x-1]);
    }
    printf("%lli\n", dp.back());
}

