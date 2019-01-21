#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, g, r, o, cst;
    scanf("%i%i%i%i%i", &p, &g, &r, &o, &cst);
    int cnt = 0, mi = INT_MAX;
    for (int x = 0; x < 50; x++)
        for (int y = 0; y < 50; y++)
            for (int z = 0; z < 50; z++)
                for (int a = 0; a < 50; a++)
                    if (x * p + y * g + z * r + a * o == cst)
                        printf("# of PINK is %i # of GREEN is %i # of RED is %i # of ORANGE is %i\n", x, y, z, a), mi = min(mi, x+y+z+a), cnt++;
    printf("Total combinations is %i.\n", cnt);
    printf("Minimum number of tickets to print is %i.", mi == INT_MAX ? 0 : mi);
}
