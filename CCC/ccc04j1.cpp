#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    scanf("%i", &a);
    printf("The largest square has side length %i.", (int)floor(sqrt(a)));
    return 0;
}
