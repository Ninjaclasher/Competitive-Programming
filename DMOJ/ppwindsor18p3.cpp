#include <bits/stdc++.h>

using namespace std;

int main()
{
    char first[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    char second[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    char third[] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    int n;
    int cnt = 0;
    scanf("%i", &n);
    while (n--)
    {
        string a;
        cin>>a;
        for (int x = 0; x < 10; x++)
        {
            if (a[0] == first[x])
            {
                for (int y = 1; y < a.length(); y++)
                {
                    bool d = 0;
                    for (int z = 0; z < 10; z++)
                        if (a[y] == first[z])
                            d = 1;
                    if (!d)
                        goto en;
                }
                cnt++;
                goto en;
            }
        }
        for (int x = 0; x < 9; x++)
        {
            if (a[0] == second[x])
            {
                for (int y = 1; y < a.length(); y++)
                {
                    bool d = 0;
                    for (int z = 0; z < 9; z++)
                        if (a[y] == second[z])
                            d = 1;
                    if (!d)
                        goto en;
                }
                cnt++;
                goto en;
            }
        }
        for (int x = 0; x < 7; x++)
        {
            if (a[0] == third[x])
            {
                for (int y = 1; y < a.length(); y++)
                {
                    bool d = 0;
                    for (int z = 0; z < 7; z++)
                        if (a[y] == third[z])
                            d = 1;
                    if (!d)
                        goto en;
                }
                cnt++;
                goto en;
            }
        }
    en:;
    }
    printf("%i\n", cnt);
}
