#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    vector<pair<int,int>> sub(1<<n);
    for (int x = 0; x < (1<<n); sub[x].second = x, x++)
        for (int y = 0; y < n; y++)
            if (x>>y&1)
                sub[x].first += arr[y];
    sort(sub.begin(), sub.end());
    int ans = 1;
    for (int x = 0; x < (1<<n)-1; x++)
        if (abs(sub[x].first-sub[x+1].first) < abs(sub[ans].first-sub[ans+1].first) && !(sub[x].second&sub[x+1].second) && sub[x].second && sub[x+1].second)
            ans = x;
    for (int x = 0; x < n; x++)
        if (sub[ans].second>>x&1)
            printf("%i ", x+1);
    printf("\n");
    for (int x = 0; x < n; x++)
        if (sub[ans+1].second>>x&1)
            printf("%i ", x+1);
    printf("\n");
}
