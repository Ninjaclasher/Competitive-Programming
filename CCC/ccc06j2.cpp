#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    int cnt = 0;
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++)
            if (x+y == 10)
                cnt++;
    printf("There");
    if (cnt == 1)
        printf(" is ");
    else
        printf(" are ");
    printf("%i way", cnt);
    if (cnt != 1)
        printf("s");
    printf(" to get the sum 10.\n");
}

