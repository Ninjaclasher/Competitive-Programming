#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h = 0, v = 0;
    string a;
    cin>>a;
    for (auto &x : a)
    {
        if (x == 'H')
            h ^= 1;
        else
            v ^= 1;
    }
    int arr[2][2] = {
        {1, 2},
        {3, 4},
    };
    if (v)
    {
        swap(arr[0][0], arr[0][1]);
        swap(arr[1][0], arr[1][1]);
    }
    if (h)
    {
        swap(arr[0][0], arr[1][0]);
        swap(arr[0][1], arr[1][1]);
    }
    for (auto &x :arr)
    {
        for (auto &y : x)
        {
            printf("%i ", y);
        }
        printf("\n");
    }
}

