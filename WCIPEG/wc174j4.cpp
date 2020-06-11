#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c, a, b, ma = 0;
    scanf("%i%i", &r, &c);
    vector<vector<char>> aa(r+1, vector<char>(c+1, 'X'));
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= c; y++)
        {
            scanf(" %c", &aa[x][y]);
            if (aa[x][y] == 'H')
                a = x, b = y;
        }
    }
    int cc = 0;
    for (int x = 1; x < a; x++)
        cc += (aa[x][b] == 'C');
    ma = max(ma, cc);
    cc = 0;
    for (int x = a+1; x <= r; x++)
        cc += (aa[x][b] == 'C');
    ma = max(ma, cc);
    cc = 0;
    for (int y = 1; y < b; y++)
        cc += (aa[a][y] == 'C');
    ma = max(ma, cc);
    cc = 0;
    for (int y = b+1; y <= c; y++)
        cc += (aa[a][y] == 'C');
    ma = max(ma, cc);
    printf("%i\n", ma);
}
