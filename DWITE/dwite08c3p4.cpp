#include <bits/stdc++.h>

using namespace std;

int main() 
{
    for (int q = 0; q < 5; q++)
    {
        int m, n;
        scanf("%i%i", &m, &n);
        vector<int> c (n);
        for (auto &x : c)
            scanf("%i", &x);
        vector<int> mm (m+1, INT_MAX);
        mm[0] = 0;
        for (int x = 0; x <= m; x++)
        {
            if (mm[x] != INT_MAX)
                for (auto &y : c)
                    if (x+y <= m)
                        mm[x+y] = min(mm[x+y], mm[x]+1);
        }
        printf("%i\n", mm[m]);
    }
}
