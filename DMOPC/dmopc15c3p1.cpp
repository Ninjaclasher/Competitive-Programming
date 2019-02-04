#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    scanf("%i%i%i%i", &a, &b, &c, &d);
    printf("%s\n", (c < b && d >= b) || (a < d && b >= d) ? "YES" : "NO");
}
