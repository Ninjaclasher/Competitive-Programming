#include <bits/stdc++.h>

using namespace std;

bool crystal(int mag, int xx, int yy)
{
    if (!mag) return false;
    int p = pow(5, mag-1);
    int pX = xx/p, pY = yy/p;
    xx%=p, yy%=p;
    if (pX && pX != 4 && !pY)
        return true;
    else if (pX == 2 && pY == 1)
        return true;
    else if ((pX == 1 || pX == 3) && pY == 1)
        return crystal(mag-1, xx, yy);
    else if (pX == 2 && pY == 2)
        return crystal(mag-1, xx, yy);
    return false;
}

int main() 
{
    int t, a, b, m;
    scanf("%i", &t);
    while (t--)
    {
        scanf("%i%i%i", &m, &a, &b);
        printf("%s\n", crystal(m, a, b) ? "crystal" : "empty");
    }
    return 0;
}
