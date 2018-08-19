#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<pair<int,int>> arr(n);
    for (auto &x : arr)
        scanf("%i%i", &x.second, &x.first);
    sort(arr.rbegin(), arr.rend());
    int a;
    multiset<int> bg;
    for (int x = 0; x < k; x++)
    {
        scanf("%i", &a);
        bg.insert(a);        
    }
    long long v = 0;
    for (int x = 0; x < n; x++)
    {
        auto it = bg.lower_bound(arr[x].second);
        if (it == bg.end())
            continue;
        bg.erase(it);
        v += arr[x].first;
    }
    printf("%lli\n", v);
}

