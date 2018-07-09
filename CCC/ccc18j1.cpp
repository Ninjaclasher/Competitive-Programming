#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int a, b, c, d;
    scanf("%i%i%i%i", &a, &b, &c, &d);
    if ((a == 8 || a == 9) && b == c && (d == 8 || d == 9))
        printf("ignore");
    else
        printf("answer");
    return 0;
}
