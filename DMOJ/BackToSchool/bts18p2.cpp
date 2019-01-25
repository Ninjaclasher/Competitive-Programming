#include <bits/stdc++.h>

using namespace std;

int psa[26][1000005];

int main()
{
    string s;
    int q, a, b;
    char c;
    getline(cin, s);
    for (int x = 0; x < s.length(); x++)
        if (s[x] != ' ')
            psa[s[x]-'a'][x] = 1;
    for (int x = 1; x < s.length(); x++)
        for (int y = 0; y < 26; y++)
            psa[y][x] += psa[y][x-1];
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i %c", &a, &b, &c);
        if (b > s.length())
            abort();
        --a, --b;
        printf("%i\n", psa[c-'a'][b]-(a ? psa[c-'a'][a-1] : 0));
    }
}
