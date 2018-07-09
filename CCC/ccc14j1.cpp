#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int a, b, c;
    scanf("%i%i%i", &a, &b, &c);
    if (a+b+c != 180)
        printf("Error");
    else if (a == b  && b == c)
        printf("Equilateral");
    else if (a == b || b == c || a == c)
        printf("Isosceles");
    else
        printf("Scalene");
    return 0;
}
