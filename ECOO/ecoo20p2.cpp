#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin>>t;
    while (t--)
    {
        map<string, vector<pair<int,int>>> mp;
        int n;
        cin>>n;
        while (n--)
        {
            int m;
            cin>>m;
            while (m--)
            {
                string s;
                int p, q;
                cin>>s>>p>>q;
                mp[s].push_back({p, q});
            }
        }
        for (auto &x : mp)
            sort(x.second.begin(), x.second.end());
        int ans = 0;
        int k;
        cin>>k;
        while (k--)
        {
            string s;
            int d;
            cin>>s>>d;
            for (auto &x : mp[s])
            {
                int sub = min(x.second, d);
                d -= sub;
                ans += sub * x.first;
            }
        }
        printf("%i\n", ans);
    }
}
