#include <bits/stdc++.h>

using namespace std;

int main()
{
    long double w, h, xx, yy;
    scanf("%Lf%Lf%Lf%Lf", &w, &h, &xx, &yy);
    long double slope = yy/(w-xx);
    for (int i = 1; i <= 1000000; i++)
    {
        long double y = slope * (i * w - xx), x = (i * h) / slope + xx;
        long double a = (int) ((y - h/2)/h + 1) * h, b = (int) ((x - w/2)/w + 1) * w;
        if (abs(a-y) < 5 || abs (b-x) < 5)
        {
            if (abs(a-y) < 5)
                printf("%i\n", i-1+ (int)(y/h) - (abs(a-y) < 1e-2));
            else
                printf("%i\n", i-1+ (int)(x/w) - (abs(b-x) < 1e-2));
            return 0;
        }
    }
    printf("0\n");
}

