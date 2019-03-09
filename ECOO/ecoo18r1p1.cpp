#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int x = 0; x < 10; x++)
    {
        int t, n;
        scanf("%i%i", &t, &n);
        int cur = 0;
        char c;
        for (int y = 1; y <= n; y++)
        {
            scanf(" %c", &c);
            if (c == 'B')
            {
                if (cur > 0)
                    cur += t;
                else
                    cur = t;
            }
            cur--;
        }
        printf("%i\n", max(0, cur));
    }
}
