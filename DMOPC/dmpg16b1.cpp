#include <stdio.h>

int main() 
{
    int n, d, q, l, t;
    scanf("%i%i%i%i%i", &n,&d,&q,&l,&t);
    printf("%i", n*5+d*10+q*25+l*100+t*200);
    return 0;
}
