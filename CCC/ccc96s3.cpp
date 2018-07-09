#include <bits/stdc++.h>

using namespace std;

string toBin(int n, int s)
{
    string a = "";
    while (n)
    {
        a+=(n&1)+'0';
        n>>=1;
    }
    while (a.length() < s) a+='0';
    reverse(a.begin(), a.end());
    return a;
}

int main() 
{
    int n, a, b;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i%i", &a, &b);
        printf("The bit patterns are\n");
        for (int x = pow(2,a)-1; x >= 0; x--)
        {
            if (__builtin_popcount(x) == b)
                cout<<toBin(x, a)<<"\n";
        }
        printf("\n");
    }
    return 0;
}
