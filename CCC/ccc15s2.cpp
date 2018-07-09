#include <bits/stdc++.h>

using namespace std;

int main()
{
    int j, a, n, c = 0;
    char s;
    scanf("%i%i", &j, &a);
    vector<char> je(j);
    vector<bool> take(j);
    for (int x = 0; x < j; x++)
        scanf(" %c", &je[x]);
    while (a--)
    {
        scanf(" %c%i", &s, &n);
        n--;
        switch(s)
        {
            case 'S':
            if (!take[n])
                c++, take[n] = true;
            break;
            case 'M':
            if (je[n] != 'S' && !take[n])
                c++, take[n] = true;
            break;
            case 'L':
            if (je[n] == 'L' && !take[n])
                c++, take[n] = true;
        }
    }
    printf("%i\n", c);
    return 0;
}
