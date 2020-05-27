#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    int l, r, y;
    scanf("%i%i%i", &l, &r, &y);
    map<long long, vector<long long>> mp;
    map<long long, int> en;
    vector<int> pos;
    for (int x = 0; x < n; x++)
    {
        long long xx, v, h;
        scanf("%lli%lli%lli", &xx, &v, &h);
        long long lx = xx + y * -h / v;
        long long rx = xx + y * h / v;
        if (y * h % v == 0)
            lx++, rx--;
        lx = max(lx, (long long)l);
        rx = min(rx, (long long)r);
        mp[lx].push_back(rx+1);
        pos.push_back(lx);
        pos.push_back(rx+1);
    }
    pos.push_back(l);
    pos.push_back(r);
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    vector<long long> ans(n+1);
    int cur_cnt = 0;
    for (int x = 0; x < pos.size(); x++)
    {
        for (auto &z : mp[pos[x]])
            en[z]++, cur_cnt++;
        cur_cnt -= en[pos[x]];
        int ll = pos[x];
        int rr = x == pos.size() - 1 ? r+1 : pos[x+1];
        ans[cur_cnt] += rr - ll;
    }
    for (int x = 1; x <= n; x++)
        ans[x] += ans[x-1];
    for (int x = 0; x <= n; x++)
        printf("%lli\n", ans[x]);
}
