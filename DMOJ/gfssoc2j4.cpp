#include <stdio.h>

int main()
{
    int n, q, a, b;
    scanf("%i%i", &n, &q);
    int val[n+1];
    val[0] = 0;
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &val[x]);
        val[x] += val[x-1];
    }
    for (int x = 0; x < q; x++)
    {
        scanf("%i%i", &a, &b);
        printf("%i\n", val[n] - val[b] + val[a-1]);
    }
    return 0;
}
