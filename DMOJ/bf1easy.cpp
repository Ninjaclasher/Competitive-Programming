#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        printf("%i%c", x, " \n"[x == n]);
}

