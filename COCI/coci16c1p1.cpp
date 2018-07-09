#include <stdio.h>

int main()
{
    int preTotal, total, months, used;
    scanf("%i", &preTotal);
    total = preTotal;
    scanf("%i", &months);
    for (int x = 0; x < months; x++)
    {
        scanf("%i", &used);
        total += preTotal - used;
    }
    printf("%i", total);
}
