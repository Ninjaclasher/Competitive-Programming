#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int x = 1000; x <= 9999; x++)
    {
        int sum = 0;
        for (int y = 1; y < x; y++)
            if (x%y == 0)
                sum += y;
        if (x == sum)
            printf("%i ", x);
    }
    printf("\n");
    for (int x = 100; x <= 999; x++)
    {
        int sum = 0;
        for (int y = x; y; y /= 10)
            sum += (y%10) * (y%10) * (y%10);
        if (x == sum)
            printf("%i ", x);
    }
    printf("\n");
}
