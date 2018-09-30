#include <bits/stdc++.h>

using namespace std;

void print(double a, double b)
{
    printf("%.2lf %.2lf", a, b);
}

int main()
{
    int a, b;
    scanf("%i%i", &a, &b);
    double area = 31250;
    //side
    if (!a)
    {
        if (b < 125)
            print(area/(250-b), 250-area/(250-b));
        else
            print(area/b, 0);
    }
    //bottom
    else if (!b)
    {
        if (a < 125)
            print(250-area/(250-a), area/(250-a));
        else
            print(0, area/a);
    }
    //hypotenuse
    else
    {
        if (a < 125)
            print(250-area/b, 0);
        else
            print(0, 250-area/a);
    }
}

