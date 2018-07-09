#include <bits/stdc++.h>

using namespace std;

struct line
{
    int x1,x2,y,t;
    line(int x, int xx, int yy, int tt) : x1(x), x2(xx), y(yy), t(tt){}
};


int main()
{
    int n, x1, x2, y1, y2;
    scanf("%i", &n);
    vector<int> rr (5000, 0), xs, ys;
    vector<line> linx, liny;
    map<int,int> mp, mpy;
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i%i%i", &x1, &y1, &x2, &y2);
        linx.push_back(line{x1,x2,y1,1});
        linx.push_back(line{x1,x2,y2,-1});
        liny.push_back(line{y1,y2,x1,1});
        liny.push_back(line{y1,y2,x2,-1});
        ys.push_back(y1);
        ys.push_back(y2);
        xs.push_back(x1);
        xs.push_back(x2);
    }
    sort(linx.begin(), linx.end(), [](line &a, line &b){return a.y < b.y;});
    sort(liny.begin(), liny.end(), [](line &a, line &b){return a.y < b.y;});
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    for (int x = 0; x < xs.size(); x++)
        mp[xs[x]] = x;
    for (int x = 0; x < ys.size(); x++)
        mpy[ys[x]] = x;
    long long cnt = 0;
    for (int x = 0; x < linx.size(); x++)
    {
        for (int y = mp[linx[x].x1]; y < mp[linx[x].x2]; y++)
            rr[y] += linx[x].t;
        if (rr[0]) cnt += (linx[x+1].y-linx[x].y);
        if (rr[xs.size()-1]) cnt += xs.back()-xs[xs.size()-2];
        for (int y = 0; y < xs.size(); y++)
        {
            if ((!rr[y] && rr[y+1]) || (rr[y] && !rr[y+1])) 
                cnt += (linx[x+1].y-linx[x].y);
        }
    }
    fill(rr.begin(), rr.end(), 0);

    for (int x = 0; x < liny.size(); x++)
    {
        for (int y = mpy[liny[x].x1]; y < mpy[liny[x].x2]; y++)
            rr[y] += liny[x].t;
        if (rr[0]) cnt += (liny[x+1].y-liny[x].y);
        if (rr[ys.size()-1]) cnt += ys.back()-ys[ys.size()-2];
        for (int y = 0; y < ys.size(); y++)
        {
            if ((!rr[y] && rr[y+1]) || (rr[y] && !rr[y+1])) 
                cnt += (liny[x+1].y-liny[x].y);
        }
    }

    printf("%lli", cnt);
    return 0;
}
