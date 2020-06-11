#include <bits/stdc++.h>

using namespace std;

char arr[105][105];

int main()
{
    int r, c;
    scanf("%i%i", &r, &c);
    for (int x = 0; x < r; x++)
        for (int y = 0; y < c; y++)
            arr[x][y] = '.';
    for (int x = 1; x < c-1; x++)
        arr[r-x-1][x] = '#';
    arr[r-1][0] = 'S';
    arr[r-2][c-1] = 'E';
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
            cout<<arr[x][y];
        cout<<endl;
    }
}
