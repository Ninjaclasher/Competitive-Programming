#include <bits/stdc++.h>

using namespace std;

bool calc(char arr[3][3], char c)
{
    for (int x = 0; x < 3; x++)
    {
        bool good1 = true, good2 = true;
        for (int y = 0; y < 3; y++)
            good1 &= arr[x][y] == c, good2 &= arr[y][x] == c;
        if (good1 || good2)
            return true;
    }
    return arr[1][1] == c && 
        ((arr[0][0] == c && arr[2][2] == c) ||
         (arr[2][0] == c && arr[0][2] == c));
}

int main()
{
    char arr[3][3];
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            scanf(" %c", &arr[x][y]);
    bool x = calc(arr, 'X');
    bool o = calc(arr, 'O');
    if (x && o)
        printf("Error, redo\n");
    else if (!x && !o)
        printf("Tie\n");
    else if (x)
        printf("Timothy\n");
    else if (o)
        printf("Griffy\n");
}
