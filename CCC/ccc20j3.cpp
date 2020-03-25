#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    int mx = INT_MIN, my = INT_MIN, mxx = INT_MAX, myy = INT_MAX;
    while (n--)
    {
        int x, y;
        scanf("%i,%i", &x, &y);
        mx = max(mx, x);
        my = max(my, y);
        mxx = min(mxx, x);
        myy = min(myy, y);
    }
    printf("%i,%i\n", mxx-1, myy-1);
    printf("%i,%i\n", mx+1, my+1);
}
