#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        string a;
        cin>>a;
        int c = 0;
        char prev = '\0';
        for (auto &x : a)
        {
            if (prev != x)
            {
                if (c)
                    printf("%i %c ", c, prev);
                c = 0;
                prev = x;
            }
            c++;
        }
        printf("%i %c\n", c, prev);
    }
}
