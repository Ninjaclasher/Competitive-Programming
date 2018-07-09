#include <bits/stdc++.h>

using namespace std;

struct line
{
    int x1,x2,y,t;
    line(int x, int xx, int yy, int tt) : x1(x), x2(xx), y(yy), t(tt){}
};

int n, m;
vector<pair<int,int>> aa;

long long sz(int q)
{
    vector<int> rr (5000, 0), xs;
    vector<line> lin;
    map<int,int> mp;
    for (auto &x : aa)
    {
        int x1 = max(x.first - q - 1, 0), x2 =  min(x.first + q, n);
        int y1 = max(x.second - q - 1, 0), y2 = min(x.second + q, m);
        lin.push_back(line{x1,x2,y1,1});
        lin.push_back(line{x1,x2,y2,-1});
        xs.push_back(x1);
        xs.push_back(x2);
    }
    sort(lin.begin(), lin.end(), [](line &a, line &b){return a.y < b.y;});
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int x = 0; x < xs.size(); x++)
        mp[xs[x]] = x;
    long long cnt = 0;
    for (int x = 0; x < lin.size(); x++)
    {
        for (int y = mp[lin[x].x1]; y < mp[lin[x].x2]; y++)
            rr[y] += lin[x].t;
        for (int y = 0; y < xs.size(); y++)
            if (rr[y] > 0) 
                cnt += static_cast<long long>(lin[x+1].y-lin[x].y)*(xs[y+1]-xs[y]);
    }
    return cnt;
}

int main()
{
    int k, q;
    scanf("%i%i%i",&n, &m, &k);
    aa.resize(k);
    for (auto &x : aa)
        scanf("%i%i", &x.first, &x.second);
    scanf("%i", &q);
    printf("%lli", sz(q) - sz(q-1));
    return 0;
}
