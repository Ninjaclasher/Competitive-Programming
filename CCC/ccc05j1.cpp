#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    scanf("%i%i%i", &a, &b, &c);
    int csta = 0, cstb = 0;
    csta += max(0, (a-100)*25);
    csta += b*15;
    csta += c*20;
    cstb += max(0, (a-250)*45);
    cstb += b*35;
    cstb += c*25;
    printf("Plan A costs %i.%02i\n", csta/100, csta%100);
    printf("Plan B costs %i.%02i\n", cstb/100, cstb%100);
    if (csta < cstb)
        printf("Plan A is cheapest.\n");
    else if (csta > cstb)
        printf("Plan B is cheapest.\n");
    else
        printf("Plan A and B are the same price.\n");
}
