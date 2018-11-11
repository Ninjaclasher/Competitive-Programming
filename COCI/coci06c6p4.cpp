/*
 * This problem is the shittiest problem I've ever seen
 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> arr(30005, vector<char>(35));

vector<vector<int>> nxt(30005, vector<int>(35));

vector<int> high(35, 2);

int r, c, n, a;

void relink(int y)
{
    while(1)
    {
        int &rr = high[y], cc = nxt[rr-1][y];
        if (rr > 2 && arr[rr-1][cc] != '.')
            --rr;
        else
        {
            char t = arr[rr][cc];
            if (rr > r || t == 'X')
                break;
            if (t == '.')
                nxt[rr][y] = cc, rr++;
            else
            {
                bool d = false;
                for (int x = -1; x <= 1 && !d; x+=2)
                {
                    if (cc+x > 0 && cc+x <= c)
                    {
                        if (arr[rr][cc+x] == '.' && arr[rr-1][cc+x] == '.')
                        {
                            nxt[rr][y] = cc+x;
                            rr++;
                            d = true;
                        }
                    }
                }
                if (!d)
                    break;
            }
        }
    }
}

int main()
{
    scanf("%i%i", &r, &c);
    for (int x = 1; x <= r; x++)
        for (int y = 1; y <= c; y++)
            scanf(" %c", &arr[x][y]);
    scanf("%i", &n);
    for (int y = 1; y <= c; y++)
        nxt[1][y] = y, relink(y);
    while (n--)
    {
        scanf("%i", &a);
        arr[high[a]-1][nxt[high[a]-1][a]] = 'O';
        for (int y = 1; y <= c; y++)
            relink(y);
    }
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= c; y++)
            printf("%c", arr[x][y]);
        printf("\n");
    }
}

