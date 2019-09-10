#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, h, v, t;
    scanf("%i%i%i%i%i", &x, &y, &h, &v, &t);
    int cx = 0, cy = 0;
    while (--t)
    {
        if (((x-cx > y-cy) || (x - cx == y-cy && h > v)) && cx + 2 < x + h)
            cx += 2, cy++;
        else
            cx++, cy += 2;
        if (x <= cx && cx < x + h && y <= cy && cy < y + v)
            break;
    }
    if (x <= cx && cx < x + h && y <= cy && cy < y + v)
        printf("YES\n");
    else
        printf("NO\n");
}
