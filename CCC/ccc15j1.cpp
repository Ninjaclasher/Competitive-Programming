#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int a;
    scanf("%i", &a);
    if (a > 2) printf("After");
    else if (a < 2) printf("Before");
    else
    {
        scanf("%i", &a);
        if (a > 18) printf("After");
        else if (a < 18) printf("Before");
        else printf("Special");
    }
    return 0;
}
