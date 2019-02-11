#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long sx, sy, sz, tx, ty, tz;
    int d;
    char t;
    scanf("%lli%lli%lli%lli%lli%lli", &sx, &sy, &sz, &tx, &ty, &tz);
    tx -= sx;
    ty -= sy;
    tz -= sz;
    long long ans = tx * tx + ty * ty + tz * tz;
    while (1)
    {
        scanf("%i %c", &d, &t);
        if ((tx - d < 0 && tx > 0) || (tx - d > 0 && tx < 0))
            ans = min(ans, ty * ty + tz * tz);
        tx -= d;
        ans = min(ans, tx * tx + ty * ty + tz * tz);
        if (t == 'E')
            return 0 * printf("%.2lf\n", sqrt(ans));
        switch(t)
        {
            case 'R':
                swap(tx, ty);
                tx = -tx;
            break;
            case 'L':
                swap(tx, ty);
                ty = -ty;
            break;
            case 'U':
                swap(tx, tz);
                tz = -tz;
            break;
            case 'D':
                swap(tx, tz);
                tx = -tx;
            break;
        }
    }
}
