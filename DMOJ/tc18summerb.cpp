#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c, d, e;
    scanf("%i%i%i", &c, &d, &e);
    if (d&e)
        return 0 * printf("0\n");
    long long cc = 1;
    for (int x = 0; x < 30; x++)
    {
        if (d>>x&1)
            continue;
        if (!(e>>x&1))
            continue;
        if (c>>x&1)
            cc *= 2;
    }
    printf("%lli\n", cc);
}
