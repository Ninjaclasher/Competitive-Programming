#include <bits/stdc++.h>

using namespace std;

char arr[15][105];


void solve()
{
    memset(arr, 0, sizeof arr);
    int j, w, h;
    scanf(" %d %d %d", &j, &w, &h);
    j = min(j, h-2);
    int pos = 0, en = 0;
    for (int x = 0; x < h; x++)
    {
        for (int y = 0; y < w; y++)
        {
            scanf(" %c", &arr[x][y]);
            if (arr[x][y] == 'L')
                pos = y;
            if (arr[x][y] == 'G')
                en = y;
        }
    }
    for (int x = pos; x < en-1; x++)
    {
        if (arr[h-2][x+1] == '.')
            continue;
        bool fail = (arr[h-2][x+2] == '@');
        for (int y = 1; y <= j; y++)
        {
            if (arr[h-2-y][x] == '@')
                break;
            if (arr[h-2-y][x+2] == '@')
                fail = true;
            if (arr[h-2-y][x+1] == '.')
            {
                if (fail)
                {
                    printf("%d\n", x+2);
                    return;
                }
                goto NXT;
            }
        }
        printf("%d\n", x+2);
        return;
NXT:;
    }
    printf("CLEAR\n");
}

int main()
{
    for (int i = 0; i < 10; i++)
        solve();
}
