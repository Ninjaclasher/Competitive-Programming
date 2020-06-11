#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b, c, d, e, f;
    scanf("%i%i", &n, &f);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        int b = a/f;
        if (a%f == 0 && (b&(b-1)) == 0)
            continue;
        printf("%i\n", x+1);
    }
}
