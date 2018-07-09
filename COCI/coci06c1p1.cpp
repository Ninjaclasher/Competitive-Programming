#include <stdio.h>

int main()
{
    int num [10];
    int temp, counter = 1;
    for (int x = 0; x < 10; x++)
    {
        scanf("%i", &temp);
        num[x] = temp % 42;
        for (int y = 0; y < x; y++)
        {
            if (num[x] == num[y]) break;
            if (y == x-1) counter++;
        }
    }
    printf("%i", counter);
    return 0;
}
