#include <bits/stdc++.h>

using namespace std;

struct box
{
    int l, w, h;
};

int main()
{
    int n, m;
    scanf("%i", &n);
    vector<box> aa(n);
    for (auto &x : aa)
        scanf("%i%i%i", &x.l, &x.w, &x.h);
    scanf("%i", &m);
    while (m--)
    {
        int l, w, h;
        int v = INT_MAX;
        scanf("%i%i%i", &l, &w, &h);
        for (auto &x : aa)
        {
            if ((l <= x.l && w <= x.w && h <= x.h)
              ||(l <= x.l && w <= x.h && h <= x.w)
              ||(l <= x.w && w <= x.l && h <= x.h)
              ||(l <= x.w && w <= x.h && h <= x.l)
              ||(l <= x.h && w <= x.w && h <= x.l)
              ||(l <= x.h && w <= x.l && h <= x.w)
              )
                v = min(v, x.l*x.w*x.h);
        }
        if (v == INT_MAX)
            printf("Item does not fit.\n");
        else
            printf("%i\n", v);
    }
}

