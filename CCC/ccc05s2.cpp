#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c, r;
    scanf("%i%i", &c, &r);
    int curx = 0, cury = 0;
    int a, b;
    for (scanf("%i%i", &a, &b); a || b; scanf("%i%i", &a, &b))
    {
        curx += a;
        cury += b;
        curx = min(curx, c);
        curx = max(curx, 0);
        cury = min(cury, r);
        cury = max(cury, 0);
        printf("%i %i\n", curx, cury);
    }
}

