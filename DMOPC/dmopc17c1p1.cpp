#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int r, c, q, xx, yy;
    char t;
    scanf("%i%i", &r, &c);
    vector<bool> cc (c+1), rr (r+1);
    for (int x = 1; x <= r; x++)
        for (int y = 1; y <= c; y++)
            {scanf (" %c", &t); if (t == 'X') rr[x] = cc[y] = true;}
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i", &xx, &yy);
        printf("%c\n", rr[yy] || cc[xx] ? 'Y' : 'N');
    }
    
    return 0;
}
