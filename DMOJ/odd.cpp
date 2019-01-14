#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b = 0;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        b ^= a;
    }
    printf("%i\n", b);
    return 0;
}
