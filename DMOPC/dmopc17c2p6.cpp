#include <bits/stdc++.h>

using namespace std;

struct ev
{
    int i, t, v;
    friend bool operator<(ev &a, ev &b)
    {
        return a.v < b.v;
    }
};

int main()
{
    int n, a, b, c = 0;
    scanf("%i", &n);
    vector<ev> evv;
    vector<int> ans(1000000);
    map<int,int> mp;
    for (int y = 0; y < 2; y++)
    {
        for (int x = 0; x < n; x++)
        {
            scanf("%i", &a);
            evv.push_back({x+1, y, a});
        }
    }
    sort(evv.begin(), evv.end());
    mp[0] = 1;
    for (int x = 0; x < evv.size(); x++)
    {
        auto it = mp.lower_bound(evv[x].i);
        auto pr = it;
        --pr;
        ans[c] = evv[x].v;
        if (it == mp.end())
            c += (pr->second != evv[x].t);
        else
        {
            if (it->first == evv[x].i)
                break;
            if (it->second == pr->second && it->second != evv[x].t)
                c += 2;
        }
        mp[evv[x].i] = evv[x].t;
    }
    for (int x = 0; x <= n; x++)
        printf("%i\n", !ans[x] ? (ans[x] = ans[x-1]) : ans[x]);
}
