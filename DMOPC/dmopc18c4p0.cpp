#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, x, y, xx, yy, mm = INT_MAX, a, b, c;
    scanf("%i%i%i", &r, &x, &y);
    for (int i = 0; i < 3; i++)
    {
        scanf("%i%i%i", &a, &b, &c);
        if (c < mm)
            mm = c, xx = a, yy = b;
    }
    if ((x-xx)*(x-xx) + (y-yy)*(y-yy) < r*r)
        printf("What a beauty!\n");
    else
        printf("Time to move my telescope!\n");
}
