#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    scanf("%i%i", &x, &y);
    for (int a = 0; a < y-x+1; a++)
        if (a%4 == 0 && a%5 == 0 && a%2 == 0 && a%3 == 0)
            printf("All positions change in year %i\n", a + x);
}
