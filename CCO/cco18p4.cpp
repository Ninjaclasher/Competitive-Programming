#include <bits/stdc++.h>

using namespace std;

int query(int x, int y)
{
    printf("? %i %i\n", x, y);
    int ret = 0;
    scanf("%i", &ret);
    return ret;
}

int main()
{
    int r, c, k;
    scanf("%i%i%i", &r, &c, &k);
    int lr = 1, rr = r, lc = 1, rc = c;
    while (rr-lr > 1 || rc-lc > 1)
    {
        int mr = lr+rr>>1, mc = lc+rc>>1;
        int v = query(mr, mc), tv = query(max(mr-1,1), mc), lv = query(mr, max(mc-1,1));
        if (tv > v)
            lr = mr;
        else
            rr = mr;
        if (lv > v)
            lc = mc;
        else
            rc = mc;
    }
    printf("! %i\n", query(lr, lc));
}
