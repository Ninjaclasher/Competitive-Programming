#include <bits/stdc++.h>

using namespace std;

int main()
{
    int qq, n;
    scanf("%i", &qq);
    while(qq--)
    {
        scanf("%i", &n);
        vector<int> a (n), b(n);
        for (auto &x : a)
            scanf("%i", &x);
        for (auto &x : b)
            scanf("%i", &x);
        int ma = 0;
        for (int x = 0; x < n; x++)
            for (int y = x; y < n; y++)
                if (b[y] >= a[x])
                    ma = max(ma, y-x);
        printf("The maximum distance is %i\n", ma);
    }
    return 0;
}
