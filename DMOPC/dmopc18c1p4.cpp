#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, k, X;
    scanf("%lli%lli%lli%lli", &n, &m, &k, &X);
    vector<pair<long long, int>> arr(n);
    vector<long long> pp(n);
    for (int x = 0; x < n; x++)
    {
        scanf("%lli", &arr[x].first);
        arr[x].second = x;
    }
    sort(arr.begin(), arr.end());
    pp[0] = arr[0].first;
    for (int x = 1; x < n; x++)
        pp[x] = pp[x-1] + arr[x].first;
    for (int x = 0; x < n-X+1; x++)
    {
        long long s = pp[x+X-1] - (x == 0 ? 0 : pp[x-1]);
        if (s-arr[x+X-1].first < k && s >= k)
        {
            vector<int> ans(n);
            for (int y = 0; y < n; y++)
                ans[arr[(x+y)%n].second] = y+1;
            for (auto &y : ans)
                printf("%i ", y);
            return 0;
        }
    }
    printf("-1\n");
}

