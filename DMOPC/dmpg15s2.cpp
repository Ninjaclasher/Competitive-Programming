#include <stdio.h>
#include <stdbool.h>

int main() {
    int r, n, w, l;
    scanf ("%i%i", &r, &n);
    int x1 [r], y1[r] , x2[r], y2[r];
    int x, y;
    bool teleported[r];
    int musicUnlock = 0;
    for (int q = 0; q < r; q++)
    {
        scanf("%i%i%i%i", &x1[q], &y1[q], &w, &l);
        x2[q] = x1[q] + w-1;
        y2[q] = y1[q] + l-1;
        teleported[q] = false;
    }
    for (int e = 0; e < n; e++)
    {
        scanf("%i%i", &x, &y);
        for (int o = 0; o < r; o++)
        {
            if (x >= x1[o] && x <= x2[o] && y >= y1[o] && y <= y2[o] && !teleported[o])
            {
                musicUnlock++;
                teleported[o] = true;
            }
        }
    }
    printf("%i", musicUnlock);
    return 0;
}
