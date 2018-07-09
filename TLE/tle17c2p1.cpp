#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    int c = 0;
    getline(cin, a);
    for (auto &x : a)
    {
        if (x != 'r' && x != 'c' && x != '(' && x != ' ')
        {
            printf("(c%cr ", x);
            c++;
        }
        if (x == ' ') break;
    }
    printf(" x");
    while (c--)
        printf(")");
}
