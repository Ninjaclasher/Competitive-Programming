#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d;
    scanf("%i", &d);
    for (int x = 1; x <= d; x++)
    {
        int s = 0, a, t;
        scanf("%i", &t);
        while (t--)
        {
            scanf("%i", &a);
            s += a;
        }
        if (!s)
            printf("Weekend\n");
        else
            printf("Day %i: %i\n", x, s);
    }
}
