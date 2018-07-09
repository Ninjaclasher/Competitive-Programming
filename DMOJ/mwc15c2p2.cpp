#include <iostream>

#define print(x) do {if (x<0) putchar_unlocked('-'), x=-x; for(_=0;x;___[_++]=x%10,x/=10); while(_--)putchar_unlocked(___[_]|'0');}while(0);
char _, __;
char ___[16];

using namespace std;

int main() 
{
    int n;
    scanf("%i", &n);
    int aa[n];
    putchar('0');
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &aa[x]);
        int a = x;
        while (a && aa[--a] <= aa[x]);
        a = x - a;
        print(a);
        putchar(' ');
    }
    return 0;
}
