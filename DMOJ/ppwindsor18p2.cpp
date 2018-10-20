#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, h;
    scanf("%i%i", &w, &h);
    for (int x = 0; x < h; x++)
    {
        for (int y = 0; y < w; y++)
            printf("%i", (x+y)&1);
        printf("\n");
    }
}
