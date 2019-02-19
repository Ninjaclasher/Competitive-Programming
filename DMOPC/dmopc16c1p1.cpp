#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, cnt = 0;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        cnt += !((a&1)^(x&1));
    }
    printf("%i\n", cnt);
}
