#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, s, h;
    scanf("%i%i%i", &t, &s, &h);
    for (int x = 0; x < t; x++)
    {
        printf("*");
        for (int y = 0; y < s; y++)
            printf(" ");
        printf("*");
        for (int y = 0; y < s; y++)
            printf(" ");
        printf("*");
        printf("\n");
    }
    for (int x = 0; x < 2 * s + 3; x++)
        printf("*");
    printf("\n");
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < 1 + s; x++)
            printf(" ");
        printf("*\n");
    }
}
