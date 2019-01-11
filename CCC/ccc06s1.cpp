#include <bits/stdc++.h>

using namespace std;

bool in(string &a, char c)
{
    return a.find(c) != -1;
}

int main()
{
    string a, b;
    cin>>a>>b;
    int n;
    scanf("%i", &n);
    while (n--)
    {
        string c;
        cin>>c;
        for (int x = 0; x < 5; x++)
        {
            if (islower(c[x]) && !(in(a, c[x]) && in(b, c[x])))
                goto no;
            else if (isupper(c[x]) && !(in(a, c[x]) || in(b, c[x])))
                goto no;
        }
        printf("Possible baby.\n");
        goto fin;
no:;
        printf("Not their baby!\n");
fin:;
    }
}
