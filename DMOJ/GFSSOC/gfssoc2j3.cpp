#include <stdio.h>

int main()
{
    char c;
    int i;
    scanf("%d", &i);
    int a = i;
    do
    {
        scanf("%c", &c);
        if (c != '=')
            scanf("%d", &i);
        if (c == 'P')
            a = a + i;
        else if (c == 'M')
            a = a - i;
    } while (c != '=');
    printf("%d", a);
}
