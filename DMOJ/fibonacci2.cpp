#include <bits/stdc++.h>

const int MOD = 1000000007;

void multiply (unsigned long long F[2][2], unsigned long long M[2][2])
{
    unsigned long long x = (F[0][0]*M[0][0]%MOD) + (F[0][1]*M[1][0]%MOD);
    unsigned long long y = (F[0][0]*M[0][1]%MOD) + (F[0][1]*M[1][1]%MOD);
    unsigned long long z = (F[1][0]*M[0][0]%MOD) + (F[1][1]*M[1][0]%MOD);
    unsigned long long w = (F[1][0]*M[0][1]%MOD) + (F[1][1]*M[1][1]%MOD);
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
 
void power(unsigned long long F[2][2], unsigned long long n)
{
    if(n <= 1)
        return;
    unsigned long long M[2][2] = {{1,1},{1,0}};
 
    power(F, n/2);
    multiply(F, F);
 
    if (n&1)
         multiply(F, M);
}

unsigned long long fib (unsigned long long n)
{
    unsigned long long F[2][2] = {{1,1},{1,0}};
    power(F, n-1);
    return F[0][0]%MOD;
}
 
int main()
{
    unsigned long long n = 0;
    int i;
    while ((i = getchar()) < '0');
    do n = (n*10+i-'0')%2000000016;
    while ((i = getchar()) >= '0');
    printf("%llu", fib(n));
    return 0;
}
