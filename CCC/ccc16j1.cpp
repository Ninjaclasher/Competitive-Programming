#include <stdio.h>
int main()
{
    char s;
    int w = 0;
    for (int x = 0; x < 6; x++)
    {
        scanf("%1s", &s);
        if (s == 'W')
            w++;
    }
    switch(w)
    {
        case 5 ... 6:
            printf("%i", 1);
            break;
        case 3 ... 4:
            printf("%i", 2);
            break;
        case 1 ... 2:
            printf("%i", 3);
            break;
        default:
            printf("%i", -1);
            break;
    }
}
