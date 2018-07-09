#include <stdio.h>
int main()
{
    int i, u;
    scanf("%i", &i);
    scanf("%i", &u);
    if (i >= 3 && u <= 4)
        printf("%s", "TroyMartian\n");
    if (i <= 6 && u >= 2)
        printf("%s", "VladSaturnian\n");
    if (i <= 2 && u <= 3)
        printf("%s", "GraemeMercurian");    
}
