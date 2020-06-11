#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%i%i", &a, &b);
    if (a >= 90)
        a = 1;
    else if (a >= 80)
        a = 2;
    else if (a >= 70)
        a = 3;
    else if (a >= 60)
        a = 4;
    else
        a = 5;
    if (b >= 90)
        b = 1;
    else if (b >= 80)
        b = 2;
    else if (b >= 70)
        b = 3;
    else if (b >= 60)
        b = 4;
    else
        b = 5;

    if (a == b)
        cout<<"Same";
    else
        cout<<"Different";
}
