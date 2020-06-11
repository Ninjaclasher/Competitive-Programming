#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr(3);
    for (auto &x : arr)
        scanf("%i", &x);
    int n;
    scanf("%i", &n);
    vector<int> vv(n);
    for (auto &x : vv)
        scanf("%i", &x), x--;

    int ans = 0;

    for (int x = 0; x < n; x++)
    {
        if (!arr[vv[x]])
            continue;
        vector<int> frst(3);
        for (int y = x+1; y < n; y++)
            if (!frst[vv[y]])
                frst[vv[y]] = y;
        int mai = 0, mi = frst[0];
        if (vv[x] == 0)
            mai = 1, mi = frst[1];
        for (int y = 0; y < 3; y++)
        {
            if (!frst[y] && y != vv[x])
            {
                mai = y;
                goto nxt;
            }
        }
        for (int y = 0; y < 3; y++)
        {
            if (frst[y] > mi && y != vv[x])
                mi = frst[y], mai = y;
        }
nxt:;
        arr[mai] += arr[vv[x]];
        ans += arr[vv[x]];
        arr[vv[x]] = 0;
    }
    cout<<ans<<endl;
}
