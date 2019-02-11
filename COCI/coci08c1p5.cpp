#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, r, c, v = -1;
    scanf("%i", &n);
    scanf("%i%i", &r, &c);
    --r;
    --c;
    pair<int,int> arr[n*n-1];
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            scanf("%i", &a);
            arr[x*n+y] = {a, x*n+y};
            if (x == r && y == c)
                v = a;
        }
    }
    set<pair<int,int>> xx[n], yy[n];
    xx[r].insert({1, c});
    yy[c].insert({1, r});
    sort(arr, arr+n*n-1);
    int ans = 1;
    int prev = -1, previ = -1;
    for (int j = 0; j < n*n-1; j++)
    {
        auto &x = arr[j];
        if (x.first <= v)
        {
            previ = j+1;
            continue;
        }
        if (prev != x.first)
        {
            for (int i = j-1; i >= 0 && i >= previ; i--)
            {
                int xP = arr[i].second/n;
                int yP = arr[i].second%n;
                int cur = arr[i].first;
                if (!~cur)
                    continue;
                xx[xP].insert({cur, yP});
                while (xx[xP].size() > 4)
                    xx[xP].erase(xx[xP].begin());
                yy[yP].insert({cur, xP});
                while (yy[yP].size() > 4)
                    yy[yP].erase(yy[yP].begin());
            }
            prev = x.first;
            previ = j;
        }
        int cur = -1;
        int xP = x.second/n;
        int yP = x.second%n;
        for (int i = -1; i <= 1; i += 2)
        {
            if (xP+i < n && xP+i >= 0)
            {
                for (auto &y : xx[xP+i])
                    if (abs(y.second-yP) > 1)
                        cur = max(cur, y.first);
            }
            if (yP+i < n && yP+i >= 0)
            {
                for (auto &y : yy[yP+i])
                    if (abs(y.second-xP) > 1)
                        cur = max(cur, y.first);
            }
        }
        if (~cur)
            cur++;
        ans = max(ans, cur);
        x.first = cur;
    }
    printf("%i\n", ans);
}
