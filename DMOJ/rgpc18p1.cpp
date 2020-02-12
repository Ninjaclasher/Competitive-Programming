#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%i%i", &a, &b);
    if (a % b == 0)
        printf("yes %i\n", a / b);
    else
    {
        int c = b;
        while (a % b)
            b++;
        printf("no %i\n", b-c);
    }
}
