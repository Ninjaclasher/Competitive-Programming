#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> arr;
int k;

void sset(int x, int y)
{
    arr[x][y] = true;
    --k;
}

void moveDown(int &x, int &y)
{
    while (k && x+1 < arr.size() && !arr[x+1][y])
        sset(x, y), ++x;
}

void moveRight(int &x, int &y)
{
    while (k && y+1 < arr[0].size() && !arr[x][y+1])
        sset(x, y), ++y;
}

void moveLeft(int &x, int &y)
{
    while (k && y-1 >= 0 && !arr[x][y-1])
        sset(x, y), --y;
}

void moveUp(int &x, int &y)
{
    while (k && x-1 >= 0 && !arr[x-1][y])
        sset(x, y), --x;
}

int main()
{
    int n, m, o, p;
    scanf("%i%i%i%i", &m, &n, &p, &o);
    arr.resize(n, vector<bool>(m));
    for (int x = 0; x < o; x++)
    {
        for (int y = 0; y < p; y++)
        {
            arr[x][y] = true;
            arr[x][m-y-1] = true;
            arr[n-x-1][y] = true;
            arr[n-x-1][m-y-1] = true;
        }
    }
    scanf("%i", &k);
    int x = 0, y = p;
    while (k)
    {
        int xx = x, yy = y;
        moveRight(x, y);
        while (k && x+1 < arr.size() && !arr[x+1][y] && (y+1 == arr[0].size() || arr[x][y+1]))
            sset(x, y), ++x;
        moveRight(x, y);
        moveDown(x, y);
        while (k && y-1 >= 0 && !arr[x][y-1] && (x+1 == arr.size() || arr[x+1][y]))
            sset(x, y), --y;
        moveDown(x, y);
        moveLeft(x, y);
        while (k && x-1 >= 0 && !arr[x-1][y] && (y-1 < 0 || arr[x][y-1]))
            sset(x, y), --x;
        moveLeft(x, y);
        moveUp(x, y);
        while (k && y+1 < arr[0].size() && !arr[x][y+1] && (x-1 < 0 || arr[x-1][y]))
            sset(x, y), ++y;
        moveUp(x, y);
        if (xx == x && yy == y)
            break;
    }
    printf("%i\n%i\n", y+1, x+1);
}
