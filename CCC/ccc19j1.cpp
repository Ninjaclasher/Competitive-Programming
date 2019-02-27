#include <bits/stdc++.h>

using namespace std;

int g()
{
    int a, b, c;
    scanf("%i%i%i", &a, &b, &c);
    return a*3 + b*2 + c;
}

int main()
{
    int a = g();
    int b = g();
    if (a > b)
        printf("A\n");
    else if (a < b)
        printf("B\n");
    else
        printf("T\n");
}
