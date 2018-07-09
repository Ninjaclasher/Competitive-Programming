#include <iostream>

int min (int a, int b)
{
    if (a >= b) return b;
    else return a;
}

int main() 
{
    int num, menuP, meals, minMenu, total = 0;
    scanf("%i", &num);
    int label[4];
    int price[num+1];
    for(int x = 1; x < num+1; x++)
        scanf("%i", &price[x]);
    scanf("%i", &menuP);
    for (int x = 0; x < 4; x++)
        scanf("%i", &label[x]);
    scanf("%i", &meals);
    int bought [meals], totalMenu [meals];
    int taken [meals+1];
    for (int x = 0; x < meals; x++)
    {
        totalMenu [x] = menuP * (x+1);
        scanf("%i", &bought[x]);
        total += price[bought[x]];
    }
    for (int y = 0; y < meals; y++)
    {
        for (int x = 1; x < meals+1; x++)
            taken[x] = 0;
        for (int x = 0; x < meals; x++)
        {
            if ((bought[x] != label[0] && bought[x] != label[1] && bought[x] != label[2] && bought[x] != label[3])||taken[bought[x]] >= y + 1)
                totalMenu[y] += price[bought[x]];
            else
                taken[bought[x]]++;
        }
    }
    for (int x = 0; x < meals; x++)
        minMenu = min(totalMenu[x], minMenu);
    printf("%i", min(total, minMenu));
    return 0;
}
