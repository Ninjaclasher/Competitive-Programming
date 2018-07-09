#include <stdio.h>

#define scan(b) scanf("%i", &b)
#define print(b) printf("%i", b)
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

int main()
{
    int n, m, tmp, h = 0;
    scan(n);
    int f[n+1], p[n];
    f[n] = 0;
    for (int x = 0; x < n; x++)
    {
        scan(f[x]);
        p[x] = 0;
    }
    scan(m);
    for (int x = 0; x < m; x++)
    {
        scan(tmp);
        scan(p[tmp-1]);
    }
    for (int x = 0; x < n; x++)
    {
        if (p[x] != 0)
        {
            if (p[x] > f[x] || p[x] > f[x+1])
            {
                h += max(f[x], f[x+1]);
                x++;
            }
            else h += f[x]-p[x];
        }
        else h += f[x];
    }
    print(h);
    return 0;
}
