#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h1, h2, w1, w2;
    scanf("%i%i%i%i", &h1, &w1, &h2, &w2);
    --h1;
    --h2;
    if (w2 * h1 > w1 * h2)
        printf("1\n");
    else if (w2 * h1 < w1 * h2)
        printf("2\n");
    else
        printf("-1\n");
}
