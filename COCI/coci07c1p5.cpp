#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, b;
    scanf("%i%i", &n, &b);
    vector<int> arr(n);
    for (auto &x : arr)
    {
        scanf("%i", &x);
        if (x < b)
            x = -1;
        else if (x == b)
            x = 0;
        else
            x = 1;
    }
    map<int,int> mp;
    long long ans = 0;
    long long cur = 0;
    for (int x = 0; x < n; x++)
    {
        if (arr[x] == 0)
        {
            for (int y = x; y >= 0; y--)
            {
                cur += arr[y];
                mp[cur]++;
            }
            cur = 0;
            for (int y = x; y < n; y++)
            {
                cur += arr[y];
                ans += mp[-cur];
            }
            break;
        }
    }
    printf("%lli\n", ans);
}
