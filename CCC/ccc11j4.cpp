#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<vector<bool>> aa (1000, vector<bool>(500, false));
    aa[400][500] = 1;
    aa[399][500] = 1;
    aa[398][500] = 1;
    aa[398][501] = 1;
    aa[398][502] = 1;
    aa[398][503] = 1;
    aa[397][503] = 1;
    aa[396][503] = 1;
    aa[396][504] = 1;
    aa[396][505] = 1;
    aa[397][505] = 1;
    aa[398][505] = 1;
    aa[398][506] = 1;
    aa[398][507] = 1;
    aa[397][507] = 1;
    aa[396][507] = 1;
    aa[395][507] = 1;
    aa[394][507] = 1;
    aa[394][506] = 1;
    aa[394][505] = 1;
    aa[394][504] = 1;
    aa[394][503] = 1;
    aa[394][502] = 1;
    aa[394][501] = 1;
    aa[394][500] = 1;
    aa[394][499] = 1;
    aa[395][499] = 1;
    aa[396][499] = 1;
    int a, pX = 396, pY = 499;
    bool dan = false;
    char c;
    scanf(" %c%i", &c, &a);
    while (c != 'q')
    {
        switch (c)
        {
            case 'd':
                for (int x = 1; x <= a; aa[pX-x][pY] = true, x++)
                    if (aa[pX-x][pY])
                        dan = true;
                pX -= a;
            break;
            case 'u':
                for (int x = 1; x <= a; aa[pX+x][pY] = true, x++)
                    if (aa[pX+x][pY])
                        dan = true;
                pX += a;
            break;
            case 'l':
                for (int x = 1; x <= a; aa[pX][pY-x] = true, x++)
                    if (aa[pX][pY-x])
                        dan = true;
                pY -= a;
            break;
            case 'r':
                for (int x = 1; x <= a; aa[pX][pY+x] = true, x++)
                    if (aa[pX][pY+x])
                        dan = true;
                pY += a;
            break;
        }
        if (dan)
            goto DANGER;
        printf("%i %i safe\n", pY-500, pX-401);
        scanf(" %c%i", &c, &a);
    }
    return 0;
    DANGER:
        printf("%i %i DANGER\n", pY-500, pX-401);
    return 0;
}
