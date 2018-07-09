#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int a, b, c, t, u = 0;
    scanf("%i%i%i%i", &a, &b, &c, &t);
    for (int x = 0; x <= t/a; x++)
    {
        for (int y = 0; y <= t/b; y++)
        {
            for (int z = 0; z <= t/c; z++)
            {
                if ((x*a)+(y*b)+(z*c) <= t && (x||y||z))
                {
                    printf("%i Brown Trout, %i Northern Pike, %i Yellow Pickerel\n", x, y, z);
                    u++;
                }
            }
        }
    }
    printf("Number of ways to catch fish: %i\n", u);
    return 0;
}
