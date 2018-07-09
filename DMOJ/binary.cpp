#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        string b;
        while (a)
        {
            int w = a&1;
            b+=w+'0';
            a>>=1;
        }
        while (b.size()%4 || b.empty()) b+='0';
        reverse(b.begin(), b.end());
        for (int x = 0; x < b.size(); x++)
        {
            printf("%c", b[x]);
            if (x % 4 == 3)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
