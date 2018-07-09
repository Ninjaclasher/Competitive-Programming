#include <bits/stdc++.h>

using namespace std;

vector<int> hh;

int ss(int dm)
{
    int bb = hh.size(), idx = -1;
    dm*=2;
    while (++idx < hh.size() && hh[idx] <= hh[0]+dm)
    {
        int cc = 1, cEnd = hh[idx], y = idx;
        while (++y < hh.size() && hh[idx] > hh[y]+dm-1000000)
            if (hh[y] > cEnd) cc++, cEnd = hh[y]+dm;
        bb = min(bb, cc);
    }
    return bb;
}

int main()
{
    int h, k, mi = 0, ma = 1000000;
    scanf("%i", &h);
    hh.resize(h);
    for (auto &x : hh)
        scanf("%i", &x);
    sort(hh.begin(), hh.end());
    scanf("%i", &k);
    if (k >= h)
    {
        printf("0\n");
        return 0;
    }
    while (ma > mi+1)
    {
        int md = (mi+ma)/2;
        if (ss (md) > k) mi = md;
        else ma = md;
    }
    printf("%i\n", ma);
}
