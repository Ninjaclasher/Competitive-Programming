#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        vector<int> mp(100);
        vector<int> arr(10);
        iota(arr.begin(), arr.end(), 0);
        string a, b, c, d;
        cin>>a>>b>>d;
        c = a+b+d;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        do
        {
            for (int x = 0; x < c.size(); x++)
                mp[c[x]] = arr[x];
            if (!mp[a[0]] || !mp[b[0]] || !mp[d[0]])
                continue;
            __int128 aa = 0, bb = 0, dd = 0;
            for (auto &x : a)
                aa = aa*10 + mp[x];
            for (auto &x : b)
                bb = bb*10 + mp[x];
            for (auto &x : d)
                dd = dd*10 + mp[x];
            if (aa+bb == dd)
            {
                for (auto &x : a)
                    x = (char)(mp[x] + '0');
                for (auto &x : b)
                    x = (char)(mp[x] + '0');
                for (auto &x : d)
                    x = (char)(mp[x] + '0');
                cout<<a<<"\n"<<b<<"\n"<<d<<endl;
                goto nxt;
            }
        }
        while (next_permutation(arr.begin(), arr.end()));
nxt:;
    }
    
}
