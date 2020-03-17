#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, v, cnt = 0;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &v);
        cnt += v > 0;
    }
    printf("%i\n", cnt);
}
