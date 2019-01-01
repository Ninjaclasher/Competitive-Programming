#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    int cnt = 0;
    long double a;
    for (int x = 0; x < n; x++)
    {
        scanf("%Lf", &a);
        if (a-(int)a < 0.5)
            cnt++;
    }
    printf("%i\n%i\n", n-cnt, cnt);
}
