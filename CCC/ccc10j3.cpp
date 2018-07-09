#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> aa (2, 0);
    int t, n;
    char a, b;
    scanf("%i", &t);
    while (t != 7)
    {
        scanf(" %c", &a);
        a -= 'A';
        if (t == 1)
            scanf("%i", &n);
        else if (t != 2)
            scanf(" %c", &b), b -= 'A';
        switch (t)
        {
            case 1: aa[a] = n; break;
            case 2: printf("%i\n", aa[a]); break;
            case 3: aa[a] += aa[b]; break;
            case 4: aa[a] *= aa[b]; break;
            case 5: aa[a] -= aa[b]; break;
            case 6: aa[a] /= aa[b]; break;
        }
        scanf("%i", &t);
    }
    return 0;
}
