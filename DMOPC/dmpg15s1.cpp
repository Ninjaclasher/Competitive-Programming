#include <stdio.h>
#include <math.h>

int main()
{
    int a, r, w, b, y, g;
    scanf("%i%i%i%i%i%i", &a, &r, &w, &b, &y, &g);
    a = a - ceil((float) r/4) - ceil((float) w/5) - ceil((float) b/4) - ceil((float) y/3) - ceil((float) g/6);
    if (a < 0)
        a = 0;
    printf("%i", a);
    return 0;
}
