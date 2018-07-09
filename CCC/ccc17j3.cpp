#include <stdlib.h>

int main() 
{
    int x1, y1, x2, y2, step, totalDif;
    scanf("%i", &x1);
    scanf("%i", &y1);
    scanf("%i", &x2);
    scanf("%i", &y2);
    scanf("%i", &step);
    totalDif = abs(x2 - x1) + abs(y2 - y1);
    char b = ((totalDif % 2 == step % 2) && step >= totalDif) ? 'Y' : 'N';
    printf("%c", b);
   return 0;
}
