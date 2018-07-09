#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int a, b, c;
    scanf("%i%i%i", &a, &b, &c);
    vector<bool> cc (c+2000);
    cc[0] = true;
    for (int x = 0; x <= c; x++)
        if (cc[x])
            cc[x+a] = cc[x+b] = true;
    for (int x = c; x >= 0; x--)
        if (cc[x])
            {printf("%i", x); return 0;}
}
