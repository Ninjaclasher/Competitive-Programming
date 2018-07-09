#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a, b, c;
    scanf("%i", &n);
    vector<int> l(2001), h(4002);
    while(n--)
    {
        scanf("%i", &a);
        l[a]++;
    }
    for (int x = 1; x <= 2000; x++)
    {
        for (int y = x; y <= 2000; y++)
        {
            if (x == y)
                h[x+y] += l[x]/2;
            else
                h[x+y] += min(l[x], l[y]);
        }
    }
    int mh = 0, mn = 0;
    for (int x = 0; x <= 4000; x++)
    {
        if (h[x] > mh)
            mh = h[x], mn = 1;
        else if (h[x] == mh)
            mn++;
    }
    printf("%i %i", mh, mn);
    return 0;
}
