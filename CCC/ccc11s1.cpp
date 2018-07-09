#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s = 0, t = 0, n;
    scanf("%i", &n);
    string a;
    cin.ignore(numeric_limits <streamsize> ::max(),'\n');
    while (n--)
    {
        getline(cin,a);
        
        for (auto &x : a)
            if (x=='S'||x=='s') s++;
            else if (x=='T'||x=='t') t++;
    }
    printf("%s\n", t>s ? "English" : "French");
}
