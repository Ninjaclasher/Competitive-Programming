#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int _ = 0; _ < 5; _++)
    {
        int v;
        scanf("%i", &v);
        bool has_1 = false;
        int x = 0;
        for (; x < 32; x++)
        {
            has_1 |= v >> x & 1;
            if ((v >> x & 1) == 0 && has_1)
                break;
        }
        v ^= 1 << x;
        v ^= 1 << (x - 1);
        int cnt = 0;
        for (int y = 0; y < x; y++)
            cnt += v >> y & 1;
        v &= ~((1 << x) - 1);
        for (int y = 0; y < cnt; y++)
            v |= 1 << y;
        printf("%i\n", v);
    }
}
