#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<int, int>> arr(n * n);
    vector<int> kk(n * n);
    for (int x = 0; x < arr.size(); x++)
        scanf("%i", &arr[x].first), arr[x].second = x, kk[x] = arr[x].first;
    sort(arr.begin(), arr.end());
    vector<int> ans(n * n);
    for (auto &x : arr)
    {
        int px = x.second / n, py = x.second % n;
        for (int t = 0; t < 4; t++)
        {
            int dx = 0, dy = 0;
            switch (t)
            {
                case 0: dx++; break;
                case 1: dx--; break;
                case 2: dy++; break;
                case 3: dy--; break;
            }
            if (0 <= px + dx && px + dx < n && 0 <= py + dy && py + dy < n && x.first > kk[(px + dx) * n + py + dy])
                ans[x.second] = max(ans[x.second], ans[(px + dx) * n + py + dy]);
        }
        ans[x.second]++;
    }
    int ma = 0;
    for (auto &x : ans)
        ma = max(ma, x);
    printf("%i\n", ma - 1);
}
