#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    printf("%i in Ottawa\n", n);
    printf("%i in Victoria\n", (n-300+2400)%2400);
    printf("%i in Edmonton\n", (n-200+2400)%2400);
    printf("%i in Winnipeg\n", (n-100+2400)%2400);
    printf("%i in Toronto\n", n);
    printf("%i in Halifax\n", (n+100)%2400);
    int hour = (n/100+25)%24;
    int min = n%100+30;
    if (min >= 60)
        min -= 60, hour = (hour+1)%24;
    hour = hour*100+min;
    printf("%i in St. John's\n", hour);
}

