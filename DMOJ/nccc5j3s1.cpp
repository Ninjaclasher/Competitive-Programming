#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    scanf("%i%i", &n, &x);
    int l = 0, e = 0, g = 0;
    while (n--)
    {
        int a;
        scanf("%i", &a);
        if (a < x)
            l++;
        else if (x == a)
            e++;
        else
            g++;
    }
    if (!e)
        printf("0\n");
    else
    {
        int cnt = 0;
        for (int y = 0; y < e; y++)
            cnt += (l+y) * (g+e-y-1);
        printf("%i\n", cnt);
    }
}
