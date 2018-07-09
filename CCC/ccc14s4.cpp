#include <bits/stdc++.h>

using namespace std;

struct ev
{
    int y, x1, x2, t;
    friend bool operator<(ev &a, ev &b)
    {
        return a.y < b.y;
    }
};

int main()
{
    int n, t;
    vector<int> xs(3000), bp(3000);
    set<int> xv;
    map<int,int> mp;
    vector<ev> eve;
    scanf("%i%i", &n, &t);
    for (int x = 0; x < n; x++)
    {
        int a, b, c, d, e;
        scanf("%i%i%i%i%i", &a, &b, &c, &d, &e);
        xv.insert(a);
        xv.insert(c);
        eve.push_back({b, a, c, e});
        eve.push_back({d, a, c, -e});
    }
    sort(eve.begin(), eve.end());
    int c = 0;
    for (auto &x : xv)
        mp[x] = c, bp[c] = x, c++;
    long long cnt = 0;
    for (int i = 0; i < eve.size(); i++)
    {
        auto x = eve[i];
        for (int y = mp[x.x1]; y < mp[x.x2]; y++)
            xs[y] += x.t;
        for (int y = 0; y < xs.size(); y++)
            if (xs[y] >= t)
                cnt += (long long)(eve[i+1].y-x.y)*(bp[y+1]-bp[y]);
    }
    printf("%lli\n", cnt);
}
