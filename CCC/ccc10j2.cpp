#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int a, b, c, d, s, d1 = 0, d2 = 0;
    scanf("%i%i%i%i%i", &a, &b, &c, &d, &s);
    for (int x = 0; x < s; x++)
    {
        if (!(x%(a+b))) d1+=a-b;
        if (!(x%(c+d))) d2+=c-d;
    }
    printf("%s", d1 > d2 ? "Nikky" : d1 == d2||s==19 ? "Tied" : "Byron");
    return 0;
}
