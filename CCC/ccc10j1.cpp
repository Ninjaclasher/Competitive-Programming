#include <stdio.h>

int main()
{
    int i;
    scanf("%i", &i);
    if (i <= 5)
        printf("%i", i /2 + 1);
    else if (i < 8)
        printf("%i", 9 - i);
    else
        printf("%i", 10 - i);
}
