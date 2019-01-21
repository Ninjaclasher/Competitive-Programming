#include <bits/stdc++.h>

using namespace std;

vector<char> mv;

vector<vector<char>> arr;
int r, c, m;

bool valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= r || y >= c)
        return false;
    return arr[x][y] != 'X';
}

void run(int x, int y, int dir)
{
    if (!valid(x, y))
        return;
    for (auto &mm : mv)
    {
        switch (mm)
        {
            case 'L':
                dir++;
                break;
            case 'R':
                dir--;
                break;
            case 'F':
                switch (dir)
                {
                    case 0:
                        x++;
                        break;
                    case 1:
                        y++;
                        break;
                    case 2:
                        x--;
                        break;
                    case 3:
                        y--;
                        break;
                }
                break;
        }
        dir %= 4;
        dir += 4;
        dir %= 4;
        if (!valid(x, y))
            return;
    }
    arr[x][y] = '*';
}

int main()
{
    scanf("%i%i", &r, &c);
    arr.resize(r, vector<char>(c));
    for (auto &x : arr)
        for (auto &y : x)
            scanf(" %c", &y);
    scanf("%i", &m);
    mv.resize(m);
    for (auto &x : mv)
        scanf(" %c", &x);
    for (int x = 0; x < r; x++)
        for (int y = 0; y < c; y++)
            for (int dir = 0; dir < 4; dir++)
                run(x, y, dir);
    for (auto &x : arr)
    {
        for (auto &y : x)
            printf("%c", y);
        printf("\n");
    }
}
