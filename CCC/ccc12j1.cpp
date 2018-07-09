#include <stdio.h>
int main()
{
    int l, r;
    scanf("%i", &l);
    scanf("%i", &r);
    int k = r - l;
    if (k>0 && k < 21)
        printf("%s", "You are speeding and your fine is $100.");
    else if (k>20 && k < 31)
        printf("%s", "You are speeding and your fine is $270.");
    else if (k>30)
        printf("%s", "You are speeding and your fine is $500.");
    else
        printf("%s", "Congratulations, you are within the speed limit!"); 
    
}
