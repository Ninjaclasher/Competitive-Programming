#include <bits/stdc++.h>

using namespace std;

int arr[10000000];
int mm[11], ll[11] = {0, 5000000, 2236, 170, 47, 21, 13, 9, 6, 5, 4};

int LSB(int i)
{
    ++i;
    return i&-i;
}

int main()
{
    int n, t, l;
    scanf("%i%i", &n, &t);
    l = ll[n];
    mm[n] = 1;
    for (int x = 0; x < n; x++)
        mm[n-x-1] = mm[n-x]*l;
    for (int x = 0; x < mm[0]; x++)
        scanf("%i", &arr[x]);
    if (t == 1)
    {
        for (int x = 1; x <= n; x++)
            for (int y = 0; y < mm[0]; y++)
                if ((y-LSB(y%mm[x-1]/mm[x])*mm[x]) >= 0 && (y-LSB(y%mm[x-1]/mm[x])*mm[x])/mm[x-1] == y/mm[x-1])
                    arr[y] += arr[y-LSB(y%mm[x-1]/mm[x])*mm[x]];
        for (int x = 1; x <= n; x++)
            for (int y = mm[0]-1; y >= mm[x]; y--)
                if ((y-mm[x])/mm[x-1] == y/mm[x-1])
                    arr[y] -= arr[y-mm[x]];
    }
    else
    {
        for (int x = 1; x <= n; x++)
            for (int y = 0; y < mm[0]; y++)
                if ((y+LSB(y%mm[x-1]/mm[x])*mm[x])/mm[x-1] == y/mm[x-1])
                    arr[y+LSB(y%mm[x-1]/mm[x])*mm[x]] += arr[y];
    }
    for (int x = 0; x < mm[0]; x++)
        printf("%i ", arr[x]);
}
